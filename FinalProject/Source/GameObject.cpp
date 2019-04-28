#include "CommonHeader.h"

GameObject::GameObject()
{
    m_Position = Vector2(0,0);
    m_Color = Vector4(1,1,1,1);
    m_Scale = Vector2(1, 1);
    m_UVScale = Vector2(1.0f, 1.0f);
    m_UVOffset = Vector2(0, 0);
}

GameObject::~GameObject()
{
}

void GameObject::Update(double TimePassed)
{
}

void GameObject::Draw()
{
    GLuint shaderprogram = g_pGame->GetShaderProgram();

    // use our shader.
    glUseProgram( shaderprogram );
}


void GameObject::SetPosition(Vector2 Pos)
{
    m_Position = Pos;
}

void GameObject::SetScale(Vector2 Scale)
{
    m_Scale = Scale;
}

void GameObject::ResetObject()
{

}

Vector2 GameObject::ObjectPosition()
{
    return m_Position;
}

Vector2 GameObject::ObjectScale()
{
    return m_Scale;
}

void GameObject::SetUpBasicUniforms(GLuint shaderprogram)
{
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

    GLint UVScale = glGetUniformLocation(shaderprogram, "u_UVScaleset");

    if (UVScale != -1)
    {
        glUniform2f(UVScale, m_UVScale.x, m_UVScale.y);
    }

    GLint UVOffset = glGetUniformLocation(shaderprogram, "u_UVOffset");

    if (UVOffset != -1)
    {
        glUniform2f(UVOffset, m_UVOffset.x, m_UVOffset.y);
    }
}

