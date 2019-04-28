#include "CommonHeader.h"

extern bool g_KeyStates[256];

Player::Player()
{
    m_Scale = Vector2(0.15f, 0.15f);
    m_Speed = 0.75f;
    m_Position.y = -0.8f;
    m_ScoreOffset = Vector2(-0.75, 0.9f);
    m_PlayerScore = 0;

    //sets up the players scoring system UI
    m_Score[0] = new NumberSystem();
    m_Score[1] = new NumberSystem();
    m_Score[2] = new NumberSystem();

    m_Score[0]->ChangeNumberPlacement(1);
    m_Score[0]->ChangeNumber(m_PlayerScore);
    m_Score[1]->ChangeNumberPlacement(10);
    m_Score[1]->ChangeNumber(m_PlayerScore);
    m_Score[2]->ChangeNumberPlacement(100);
    m_Score[2]->ChangeNumber(m_PlayerScore);

    //Sets up the score positioning and adding in a offset to each one
    m_Score[0]->SetPosition(m_ScoreOffset + Vector2(m_Score[0]->ObjectScale().x + 0.025f,0.0f));
    m_Score[1]->SetPosition(m_ScoreOffset);
    m_Score[2]->SetPosition(m_ScoreOffset - Vector2(m_Score[0]->ObjectScale().x + 0.025f, 0.0f));
}

Player::~Player()
{
}


void Player::Update(double TimePassed)
{
    //Makes sure so that the player cannot go off the screen
    if (g_KeyStates[VK_LEFT] && m_Position.x > -1 + m_Scale.x)
    {
        m_Position.x -= TimePassed * m_Speed;
    }
    //Makes sure so that the player cannot go off the screen
    if (g_KeyStates[VK_RIGHT] && m_Position.x < 1 - m_Scale.x)
    {
        m_Position.x += TimePassed * m_Speed;
    }

	// check if we're colliding with any enemies.
	for (int i = 0; i< g_pGame->GetDropCount(); i++)
	{
		Collectibles* Drops = g_pGame->GetDrops(i);
		
		float Distance = sqrtf((Drops->ObjectPosition().x - m_Position.x) * (Drops->ObjectPosition().x - m_Position.x) +
			(Drops->ObjectPosition().y - m_Position.y) * (Drops->ObjectPosition().y - m_Position.y));

		if (Distance < (m_Scale.x + Drops->ObjectScale().x))
		{
			AddToScore(Drops->ScoreValue());
			Drops->ResetCollectible();
		}

	}

}

void Player::Draw()
{
    GLuint shaderprogram2 = g_pGame->GetSecondShaderProgram();
    glUseProgram(shaderprogram2);

    GLint loctex = glGetUniformLocation(shaderprogram2, "u_Texture");


    SetUpBasicUniforms(shaderprogram2);

    if (loctex != -1)
    {
        glUniform1i(loctex, 1);
    }

    DrawSquare(shaderprogram2);

    m_Score[0]->Draw();
    m_Score[1]->Draw();
    m_Score[2]->Draw();
}

void Player::UpdateScoreText(int Score)
{
	m_Score[0]->ChangeNumber(Score);
	m_Score[1]->ChangeNumber(Score);
	m_Score[2]->ChangeNumber(Score);
}


void Player::AddToScore(int Amount)
{
	if ((m_PlayerScore + Amount) <= 0)
	{
		m_PlayerScore = 0;
	}
	else
	{
		m_PlayerScore += Amount;
    }

	UpdateScoreText(m_PlayerScore);
}