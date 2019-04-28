#ifndef __RandomShapes_H__
#define __RandomShapes_H__
class RandomShapes : public GameObject
{
public:
	RandomShapes();
	virtual ~RandomShapes();

	virtual void Update(double TimePassed);
	virtual void Draw();
private:

	//Used to store the cycling stuff for the shape
	int m_CycleNum;
	float m_CycleTimer;
};

#endif

