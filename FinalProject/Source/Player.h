#ifndef __Player_H__
#define __Player_H__
#include "NumberSystem.h"

class Player : public GameObject
{
public:
    Player();
    virtual ~Player();

    virtual void Update(double TimePassed);
    virtual void Draw();

	//Adds to the score and updates the score text
	void AddToScore(int Amount);

private:
	void UpdateScoreText(int Score);
    float m_Speed;
    NumberSystem* m_Score[3];
    Vector2 m_ScoreOffset;


    int m_PlayerScore;
    
};

#endif //__Game_H__
