#include "CommonHeader.h"
#include "NumberSystem.h"


NumberSystem::NumberSystem()
{
    m_UVScale = Vector2(10.0f, 1.0f);
    m_Scale = Vector2(0.1f, 0.1f);
    m_UVOffset = Vector2(0, 0);

    m_DisplayNumber = 0;
}


NumberSystem::~NumberSystem()
{
}


void NumberSystem::Draw()
{
    GLuint shaderprogram2 = g_pGame->GetSecondShaderProgram();
    glUseProgram(shaderprogram2);

    SetUpBasicUniforms(shaderprogram2);

    GLint loctex = glGetUniformLocation(shaderprogram2, "u_Texture");

    if (loctex != -1)
    {
        glUniform1i(loctex, 7);
    }

    DrawSquare(shaderprogram2);
}


void NumberSystem::ChangeNumber(int number)
{
    m_DisplayNumber = number / m_Placement;

    m_UVOffset.x = m_DisplayNumber * 0.1f;
}

void NumberSystem::ChangeNumberPlacement(int number)
{
    m_Placement = number;
}