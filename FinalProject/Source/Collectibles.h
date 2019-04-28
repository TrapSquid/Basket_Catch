#ifndef __Collectibles_H__
#define __Collectibles_H__

#include "functions.h"

class Collectibles : public GameObject
{
public:
    Collectibles();
    virtual ~Collectibles();
    virtual void Draw();
	virtual void Update(double TimePassed);

	//Is called when changing up the object that will fall down and also reset it
	void ResetCollectible();

	//Is called by the player to see how much the score amount is for the fruit
	int ScoreValue();

private:

	int m_CollectibleNumber;
	int m_ScoreAmount;
	int m_MissScore;

};

#endif

