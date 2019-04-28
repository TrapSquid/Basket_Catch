#ifndef __LevelTile_H__
#define __LevelTile_H__

class Camera;

class LevelTile : public GameObject
{
public:
    LevelTile();
    virtual ~LevelTile();

    virtual void Draw();

    //Runs through the camera loadcontent which will only be called once.
    void CameraLoadcontent(Vector2 CameraHeightnWidth, Vector2 CameraPosition);

    //Sets up the Camera Positioning.
    void SetCameraPosition(Vector2 Position);
    void SetCameraScale(Vector2 Scale);

protected:

    //This function is called inside of this class to bind the textures
    void BindTextures();

    //This is the camera that is set onto the player.
    Camera* m_Camera;

    //Holds how the camera acts
    Vector2 m_CameraPosition;
    Vector2 m_CameraScale;

    GLuint m_TexturesIndex[8];
};

#endif //__LevelTile_H__