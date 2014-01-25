#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject
{
public:
    GameObject(int x, int y);
    ~GameObject();

    int getX();
    int getY();

    virtual void update();
    virtual void draw();

protected:
    int m_x;
    int m_y;
};

#endif
