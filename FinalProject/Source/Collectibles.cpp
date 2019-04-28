#include "CommonHeader.h"
#include "Collectibles.h"


Collectibles::Collectibles()
{
	m_Scale = Vector2(0.15f, 0.15f);
	m_Position = Vector2(0.0f, 1.5f);

	m_MissScore = -2;

	ResetCollectible();
}


Collectibles::~Collectibles()
{
}

void Collectibles::Draw()
{
	GLuint shaderprogram2 = g_pGame->GetSecondShaderProgram();
	glUseProgram(shaderprogram2);

	GLint loctex = glGetUniformLocation(shaderprogram2, "u_Texture");


	SetUpBasicUniforms(shaderprogram2);

	if (loctex != -1)
	{
		glUniform1i(loctex, m_CollectibleNumber);
	}

	DrawSquare(shaderprogram2);
}


void Collectibles::Update(double TimePassed)
{
	m_Position.y -= TimePassed;

	if (m_Position.y < -1 - m_Scale.y)
	{
		//Makes sure that bombs dont decrease the score when dodged
		if (m_CollectibleNumber != 6)
		{
			g_pGame->GetPlayer()->AddToScore(m_MissScore);
		}
		ResetCollectible();
	}
}


void Collectibles::ResetCollectible()
{
	//Resets the position of the collectible
	m_Position = Vector2(CreateRandomNumber(-100, 100) *0.01f, (CreateRandomNumber(1, 200) *0.01f) + 1);

	//Generates a random number between 2 and 6
	m_CollectibleNumber = CreateRandomNumber(2, 6);

	//This switchs statment cycles through the numbers and changes the points depending on the sprite
	switch (m_CollectibleNumber)
	{
	case 2:
		m_ScoreAmount = 1;
		break;
	case 3:
		m_ScoreAmount = 2;
		break;
	case 4:
		m_ScoreAmount = 3;
		break;
	case 5:
		m_ScoreAmount = 4;
		break;
	case 6:
		m_ScoreAmount = -5;
		break;
	default:

		break;
	}
}


int Collectibles::ScoreValue()
{
	return m_ScoreAmount;
}
