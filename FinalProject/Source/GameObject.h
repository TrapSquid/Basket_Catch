#ifndef __GameObject_H__
#define __GameObject_H__

class GameObject
{
protected:
    //Holds the position of the object
    Vector2 m_Position;
    //Holds the color of the object
    Vector4 m_Color;
    //Holds the scaling ratio for the object
    Vector2 m_Scale;
    //Used for holding onto the objects UV's changing data.
    Vector2 m_UVScale;
    Vector2 m_UVOffset;

    virtual void SetUpBasicUniforms(GLuint shaderprogram);


public:
    GameObject();
    virtual ~GameObject();

    virtual void Update(double TimePassed);
    virtual void Draw();

	//Mainly these are all objects that if something needs this function that you will allow you to polymorph the functions -- If unused wont do much but the default functions
	//this returns the position of the object
	virtual Vector2 ObjectPosition();

	//This returns the object scale for object
	virtual Vector2 ObjectScale();

	//This sets the objects position
	virtual void SetPosition(Vector2 Pos);

	//this sets the objects scaling
	virtual void SetScale(Vector2 Scale);

	//allows for the objects to get called to resetted
	virtual void ResetObject();
};

#endif //__Game_H__
