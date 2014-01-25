#ifndef HUD_HPP
#define HUD_HPP

class HUD
{
public:
    HUD(int x, int y, int width, int height);
    ~HUD();

    virtual void update();
    virtual void draw();

protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

#endif