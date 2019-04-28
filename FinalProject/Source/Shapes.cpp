#include "CommonHeader.h"

GLuint g_VBOSquare = 0;
GLuint g_VBOTriangle = 0;
GLuint g_VBOCircle = 0;
GLuint g_VBORandom1 = 0;
GLuint g_VBORandom2 = 0;
GLuint g_VBORandom3 = 0;

const int CIRCLE_SLICES = 100;
const float CIRCLE_RADIUS = 1.0f;

void GenerateTriangle()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated
    assert( g_VBOTriangle == 0 );

    // vertex position info for a triangle
	float vertexattributes[] = { 0.0f, 1.0f,
								-0.7071f, -0.7071f, 
								0.7071f, -0.7071f };

    // gen and fill buffer with our attributes
    glGenBuffers( 1, &g_VBOTriangle );
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOTriangle );
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*6, vertexattributes, GL_STATIC_DRAW );

    // check for errors
    CheckForGLErrors();
}

void DrawTriangle(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOTriangle );

    GLint loc = glGetAttribLocation( shaderprogram, "a_Position" );
    if( loc != -1 )
    {
        glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, (void*)0 );
        glEnableVertexAttribArray( loc );
    }

    // check for errors
    CheckForGLErrors();

    glDrawArrays( GL_TRIANGLES, 0, 3 );
}

void GenerateCircle()
{
	//Holds onto the values passed in for later use.
	const int Slices = CIRCLE_SLICES;
	float Convert = Slices;

	// ATM this can only be called once, so we assert if it's called again with a VBO already allocated
	assert(g_VBOCircle == 0);
	
	//Cycles between all the segments needed to generate the circle
	float vertexattributes[6*Slices];
	for (int i = 0; i < CIRCLE_SLICES; i++)
	{
		vertexattributes[1 + (i * 6) - 1] = 0;
		vertexattributes[2 + (i * 6) - 1] = 0;
	
		//Sets the positioning according to the angle to be drawn.
		vertexattributes[3 + (i * 6) - 1] = cosf((360 / Convert * (i + 1)) * PI / 180);// *CIRCLE_RADIUS;
		vertexattributes[4 + (i * 6) - 1] = sinf((360 / Convert * (i + 1)) * PI / 180);// *CIRCLE_RADIUS;
												  
		vertexattributes[5 + (i * 6) - 1] = cosf((360 / Convert * (i + 2)) * PI / 180);// *CIRCLE_RADIUS;
		vertexattributes[6 + (i * 6) - 1] = sinf((360 / Convert * (i + 2)) * PI / 180);// *CIRCLE_RADIUS;
	}

	// gen and fill buffer with our attributes
	glGenBuffers(1, &g_VBOCircle);
	glBindBuffer(GL_ARRAY_BUFFER, g_VBOCircle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 2 * 3 * CIRCLE_SLICES , vertexattributes, GL_STATIC_DRAW);

	// check for errors
	CheckForGLErrors();
}

void DrawCircle(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOCircle );

	GLint loc = glGetAttribLocation(shaderprogram, "a_Position");
	if (loc != -1)
	{
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		glEnableVertexAttribArray(loc);
	}

    // check for errors
    CheckForGLErrors();

	glDrawArrays(GL_TRIANGLES, 0, 3 *CIRCLE_SLICES);
}

void GenerateSquare()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated
    assert( g_VBOSquare == 0 );

    // vertex position info for a triangle
    VertexFormat vertexattributes[] =
    {
        { -1.0f, 1.0f, 0, 1.0f, },
        { -1.0f, -1.0f, 0.0f, 0.0f, },
        { 1.0f, -1.0f, 1.0f, 0.0f, },

        { -1.0f, 1.0f, 0, 1.0f, },
        { 1.0f, 1.0f, 1.0f, 1.0f, },
        { 1.0f, -1.0f, 1.0f, 0.0f, },
    };

    // gen and fill buffer with our attributes
    glGenBuffers( 1, &g_VBOSquare );
    glBindBuffer(GL_ARRAY_BUFFER, g_VBOSquare);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 6, vertexattributes, GL_STATIC_DRAW);

    // check for errors
    CheckForGLErrors();
}

void DrawSquare(GLuint shaderprogram)
{
    glBindBuffer( GL_ARRAY_BUFFER, g_VBOSquare );

    GLint loc = glGetAttribLocation( shaderprogram, "a_Position" );
    if( loc != -1 )
    {
        glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 16, (void*)0);
        glEnableVertexAttribArray( loc );
    }
    

    GLint UV = glGetAttribLocation(shaderprogram, "a_UV");
    if (UV != -1)
    {
        glVertexAttribPointer(UV, 2, GL_FLOAT, GL_FALSE, 16, (void*)8);
        glEnableVertexAttribArray(UV);
    }

    // check for errors
    CheckForGLErrors();

    glDrawArrays(GL_TRIANGLES, 0, 6);
}



void GenerateRandom1()
{
	// ATM this can only be called once, so we assert if it's called again with a VBO already allocated
	assert(g_VBORandom1 == 0);

	// vertex position info for a triangle
	float vertexattributes[] = 

		//Top
		{ 0.0f, 1.0f,
		-0.5f, 0.5f,
		0.5f, 0.5f,
		
		//Left
		-1.0f, 0.0f,
		0.5f, 0.5f,
		-0.5f, -0.5f, 
		

		//right
		1.0f, 0.0f,
		-0.5f, 0.5f,
		0.5f, -0.5f,
	
		//Down
		0.0f, -1.0f,
		-0.5f, -0.5f,
		0.5f, -0.5f, };

	// gen and fill buffer with our attributes
	glGenBuffers(1, &g_VBORandom1);
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, vertexattributes, GL_STATIC_DRAW);

	// check for errors
	CheckForGLErrors();
}

void DrawRandom1(GLuint shaderprogram)
{
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom1);

	GLint loc = glGetAttribLocation(shaderprogram, "a_Position");
	if (loc != -1)
	{
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		glEnableVertexAttribArray(loc);
	}

	// check for errors
	CheckForGLErrors();

	glDrawArrays(GL_TRIANGLES, 0, 3 * 4);
}


void GenerateRandom2()
{
	// ATM this can only be called once, so we assert if it's called again with a VBO already allocated
	assert(g_VBORandom2 == 0);

	// vertex position info for a triangle
	float vertexattributes[] =

		//Top Left
	
		{ 0.0f, 1.0f,
		-0.75f, 0.75f,
		-0.5f, 0.0f,

		//Top Right
		0.0f, 1.0f,
		0.75f, 0.75f,
		0.5f, 0.0f,


		//Bottum
		-0.5f, 0.0f,
		0.5f, 0.0f,
		0.0f, -0.5f,

		//Down
		0.0f, -1.0f,
		-0.5f, -0.5f,
		0.5f, -0.5f, };

	// gen and fill buffer with our attributes
	glGenBuffers(1, &g_VBORandom2);
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, vertexattributes, GL_STATIC_DRAW);

	// check for errors
	CheckForGLErrors();
}

void DrawRandom2(GLuint shaderprogram)
{
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom2);

	GLint loc = glGetAttribLocation(shaderprogram, "a_Position");
	if (loc != -1)
	{
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		glEnableVertexAttribArray(loc);
	}

	// check for errors
	CheckForGLErrors();

	glDrawArrays(GL_TRIANGLES, 0, 3 * 4);
}


void GenerateRandom3()
{
	// ATM this can only be called once, so we assert if it's called again with a VBO already allocated
	assert(g_VBORandom3 == 0);

	// vertex position info for a triangle
	float vertexattributes[] =

		//Top Left

	{ -1.0f, 1.0f,
	0.0f, 1.0f,
	-1.0, 0.5f,

		//Top Right
		1.0f, 1.0f,
		0.0f, 1.0f,
		1.0, 0.5f,


		//Bottumleft
		-1.0f, -1.0f,
		0.0f, -1.0f,
		-1.0, -0.5f,

		//BottumRight
		1.0f, -1.0f,
		0.0f, -1.0f,
		1.0, -0.5f,

		//Middleleft
		0.0f, 0.0f,
		-1.0f, 0.5f,
		-1.0f, -0.5f,

		//MiddleRight
		0.0f, 0.0f,
		1.0f, 0.5f,
		1.0f, -0.5f 
	};

	// gen and fill buffer with our attributes
	glGenBuffers(1, &g_VBORandom3);
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 6, vertexattributes, GL_STATIC_DRAW);

	// check for errors
	CheckForGLErrors();
}

void DrawRandom3(GLuint shaderprogram)
{
	glBindBuffer(GL_ARRAY_BUFFER, g_VBORandom3);

	GLint loc = glGetAttribLocation(shaderprogram, "a_Position");
	if (loc != -1)
	{
		glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void*)0);
		glEnableVertexAttribArray(loc);
	}

	// check for errors
	CheckForGLErrors();

	glDrawArrays(GL_TRIANGLES, 0, 3 * 6);
}
