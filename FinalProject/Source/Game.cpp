#include "CommonHeader.h"
#include <time.h>

Game* g_pGame = 0;

extern bool g_KeyStates[256];

float Test = 0;

Game::Game()
{
    g_pGame = this;

    m_WindowWidth = -1;
    m_WindowHeight = -1;

    m_pShader = 0;
    m_pSecondShader = 0;

    m_Level = 0;

    m_Player = 0;

	m_RandomShape = 0;

	m_FallingObjectCount =5;

	m_TimeScale = 30;
}

Game::~Game()
{
    delete m_pShader;
    delete m_pSecondShader;

    glDeleteBuffers( 1, &g_VBOSquare );
    glDeleteBuffers( 1, &g_VBOTriangle );
    glDeleteBuffers( 1, &g_VBOCircle );

    delete m_Level;

    delete m_Player;

	delete m_RandomShape;
}

void Game::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    m_WindowWidth = width;
    m_WindowHeight = height;
}

void Game::LoadContent()
{
    // turn on depth buffer testing.
    //glEnable( GL_DEPTH_TEST );
    //glDepthFunc( GL_LESS );
    // turn on alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    // create our shaders.
    m_pShader = new ShaderProgram( "Data/Shaders/white.vert", "Data/Shaders/white.frag" );

    //Creates the shader that deals with textures
    m_pSecondShader = new ShaderProgram("Data/Shaders/Blue.vert", "Data/Shaders/Blue.frag");
    

	//sets up the level values
    m_Level = new LevelTile();
    m_Level->CameraLoadcontent( Vector2((float)m_WindowHeight, (float)m_WindowWidth), Vector2(0, 0));

    m_Player = new Player();

	m_RandomShape = new RandomShapes();

    CheckForGLErrors();

    GenerateSquare();
	GenerateCircle();
    GenerateTriangle();
	GenerateRandom1();
	GenerateRandom2();
	GenerateRandom3();
    

    CheckForGLErrors();
}

void Game::Update(double TimePassed)
{
	m_TimeScale += TimePassed;

	//Safe check so doesnt go over 100
	if (m_FallingObjectCount < MAX_DROPS)
	{
		m_FallingObjectCount = 2 * (m_TimeScale / 15);
	}


    m_Player->Update(TimePassed);
	m_RandomShape->Update(TimePassed);

	for (int i = 0; i < m_FallingObjectCount; i++)
	{
		m_FallingObjects[i].Update(TimePassed);
	}
}

void Game::Draw()
{
    // clear the screen to dark blue.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glUseProgram(m_pShader->m_Program);

    //Draws the level
    m_Level->Draw();

	for (int i = 0; i < m_FallingObjectCount; i++)
	{
		m_FallingObjects[i].Draw();
	}

	//Draws the player
	m_Player->Draw();


	m_RandomShape->Draw();

	
    CheckForGLErrors();
}


//This function is called for when the level will reset
void Game::Reset()
{
	m_FallingObjectCount = 1;

	for (int i = 0; i < m_FallingObjectCount; i++)
	{
		m_FallingObjects[i].ResetCollectible();
	}

	m_Player = nullptr;
	m_Player = new Player();
}
