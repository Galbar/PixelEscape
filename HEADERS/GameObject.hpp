class GameObject
{
public:
    GameObject();
    GameObject(int x, int y);
    ~GameObject();

    int getX();
    int getY();

    virtual void update();
    virtual void draw();

private:
    int m_x;
    int m_y;
};