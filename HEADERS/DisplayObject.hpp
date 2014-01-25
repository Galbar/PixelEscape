#ifndef DISPLAYOBJECT_HPP
#define DISPLAYOBJECT_HPP

#include "Input.hpp"

class DisplayObject {
public:
	DisplayObject(int x, int y, int width, int height);
    ~DisplayObject();

    virtual void draw();
    virtual void update();

protected:
    int m_x;
    int m_y;	
    int m_width;
    int m_height;
    Input m_input;

};
#endif