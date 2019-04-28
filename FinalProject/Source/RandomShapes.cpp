#include "CommonHeader.h"
#include "RandomShapes.h"


RandomShapes::RandomShapes()
{
	m_Scale = Vector2(0.1f, 0.1f);
	m_Color = Vector4(1, 0, 1, 1);
	m_Position = Vector2(0.0f, 0.9f);

	m_CycleNum = 2;
	m_CycleTimer = 0;
}


RandomShapes::~RandomShapes()
{
	
}


void RandomShapes::Update(double TimePassed)
{
	m_CycleTimer += TimePassed;
	if (m_CycleTimer > 1)
	{
		++m_CycleNum;
		m_CycleTimer = 0;
		if (m_CycleNum >= 3)
		{
			m_CycleNum = 0;
		}
	}
}
void RandomShapes::Draw()
{
	GLuint shaderprogram = g_pGame->GetShaderProgram();
	glUseProgram(shaderprogram);


	GLint Pos = glGetUniformLocation(shaderprogram, "u_ChangePosition");

	if (Pos != -1)
	{
		glUniform2f(Pos, m_Position.x, m_Position.y);
	}

	GLint Scale = glGetUniformLocation(shaderprogram, "u_ObjectScale");

	if (Scale != -1)
	{
		glUniform2f(Scale, m_Scale.x, m_Scale.y);
	}

	GLint Color = glGetUniformLocation(shaderprogram, "u_Color");

	if (Color != -1)
	{
		glUniform4f(Color, m_Color.x, m_Color.y, m_Color.z, m_Color.w);
	}

	GLint Time = glGetUniformLocation(shaderprogram, "u_Time");

	if (Time != -1)
	{
		glUniform1f(Time,(m_CycleTimer * 2) - 1);
	}

	//cyles through diffrent shapes to draw
	switch (m_CycleNum)
	{
	case 1:
		DrawRandom1(shaderprogram);
		break;
	case 2:
		DrawRandom2(shaderprogram);
		break;
	case 3:
		DrawRandom3(shaderprogram);
		break;
	default:
		DrawRandom3(shaderprogram);
		break;
	}
}