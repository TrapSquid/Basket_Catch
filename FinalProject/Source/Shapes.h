#ifndef __Shapes_H__
#define __Shapes_H__

extern GLuint g_VBOSquare;
extern GLuint g_VBOTriangle;
extern GLuint g_VBOCircle;
extern GLuint g_VBORandom1;
extern GLuint g_VBORandom3;

void GenerateTriangle();
void DrawTriangle(GLuint shaderprogram);

void GenerateCircle();
void DrawCircle(GLuint shaderprogram);

void GenerateSquare();
void DrawSquare(GLuint shaderprogram);

void GenerateRandom1();
void DrawRandom1(GLuint shaderprogram);

void GenerateRandom2();
void DrawRandom2(GLuint shaderprogram);

void GenerateRandom3();
void DrawRandom3(GLuint shaderprogram);

struct VertexFormat
{
    float m_Position[2];
    float m_UV[2];
};

#endif //__Game_H__
