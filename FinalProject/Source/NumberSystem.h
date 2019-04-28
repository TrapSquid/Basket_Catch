#ifndef __NumberSystem_H__
#define __NumberSystem_H__

class NumberSystem : public GameObject
{
public:
    NumberSystem();
    virtual ~NumberSystem();
    virtual void Draw();

    //Changes the number of the current number
    void ChangeNumber(int number);

    //Moves over the placement of the number. 
    //IE 1's, 10's, 100's
    void ChangeNumberPlacement(int number);


private:
    //The score number that the number system will hold onto
    int m_DisplayNumber;
    //Holds onto the placement to where its one
    //IE 1's, 10's, 100's
    int m_Placement;

};

#endif
