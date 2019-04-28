#include "CommonHeader.h"
#include "LevelTile.h"


LevelTile::LevelTile()
{
    m_Camera = new Camera();

    //Loads the texture for the background
    m_TexturesIndex[0] = LoadTexture("Data/Background.png");

    //Loads the texture for the player
    m_TexturesIndex[1] = LoadTexture("Data/Basket.png");

	//Loads the texture for the collectibles that fall down the screen
	m_TexturesIndex[2] = LoadTexture("Data/Grapes.png");
	m_TexturesIndex[3] = LoadTexture("Data/Strawberry.png");
	m_TexturesIndex[4] = LoadTexture("Data/Apple.png");
	m_TexturesIndex[5] = LoadTexture("Data/Cherries.png");
	m_TexturesIndex[6] = LoadTexture("Data/bomb-4.png");

    //Loads the texture for the player
    m_TexturesIndex[7] = LoadTexture("Data/Counter.png");
}


LevelTile::~LevelTile()
{
    m_Camera = nullptr;
    delete m_Camera;
}

void LevelTile::Draw()
{
    GLuint shaderprogram2 = g_pGame->GetSecondShaderProgram();
    glUseProgram(shaderprogram2);

    SetUpBasicUniforms(shaderprogram2);

    //Bind textures for use
    //This function is located further down.
    BindTextures();

    GLint loctex = glGetUniformLocation(shaderprogram2, "u_Texture");

    if (loctex != -1)
    {
        glUniform1i(loctex, 0);
    }

    m_Camera->Draw();
    DrawSquare(shaderprogram2);
}

void LevelTile::CameraLoadcontent(Vector2 CameraWidthnHeight, Vector2 CameraPosition)
{

    m_Camera->SetCameraHeightWidth(CameraWidthnHeight.x, CameraWidthnHeight.y);
    m_Camera->SetCameraPosition(CameraPosition);
}

void LevelTile::BindTextures()
{
    //Binds the background texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[0]);

    //Binds the player texture
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[1]);

	//Binds the textures that are used for the falling gameobjects
	//apple
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[2]);
	//grapes
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[3]);
	//strawberrys
	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[4]);
	//cherries
	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[5]);
	//bomb
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[6]);


    //Binds the NumberSystem texture
    glActiveTexture(GL_TEXTURE7);
    glBindTexture(GL_TEXTURE_2D, m_TexturesIndex[7]);
}