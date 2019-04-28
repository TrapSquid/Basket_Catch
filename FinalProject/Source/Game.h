#ifndef __Game_H__
#define __Game_H__

#include "Camera.h"

class Game;

extern Game* g_pGame;

class ShaderProgram;

class Game
{
public:
    static const int MAX_DROPS = 100;

protected:
    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;

    ShaderProgram* m_pShader;
    ShaderProgram* m_pSecondShader;

    LevelTile* m_Level;
	Player* m_Player;
	Collectibles m_FallingObjects[MAX_DROPS];

	RandomShapes* m_RandomShape;

	//holds the time to calculate through the time.
	int m_FallingObjectCount;

	//This function starts off at 30 and every 15 seconds after that it adds 2 to the drop count
	float m_TimeScale;



public:
    Game();
    virtual ~Game();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    virtual void Update(double TimePassed);
    virtual void Draw();

    void Reset();


	Collectibles* GetDrops(int i) { return &m_FallingObjects[i]; }
	int GetDropCount() { return m_FallingObjectCount; }

	Player* GetPlayer() { return m_Player; }

    GLuint GetShaderProgram() { return m_pShader->m_Program; }

    GLuint GetSecondShaderProgram() { return m_pSecondShader->m_Program; }
};

#endif //__Game_H__
