#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

struct PlayerConfig
{
    vector<sf::Keyboard::Key> keyMap;
};

#define MOVEUP 0
#define MOVERIGHT 1
#define MOVEDOWN 2
#define MOVELEFT 3
#define ALTMOVEUP 4
#define ALTMOVERIGHT 5
#define ALTMOVEDOWN 6
#define ALTMOVELEFT 7
#define JOINCOMPONENTS 8
#define SELECTR 9
#define SELECTG 10
#define SELECTB 11
#define SELECTOTHER 12

#define POINTERX 0
#define POINTERY 1

#define MAPPINGSIZE 13
#define VALUESIZE 2

class Input
{
private:
    vector<sf::Keyboard::Key> keys;

    int mapSize;
    int valueMapSize;
    sf::RenderWindow* m_window;

public:

    vector<bool> keysPressed;
    vector<bool> keysOldPressed;
    vector<float> keyValues;
    Input();
    Input(vector<sf::Keyboard::Key> v, sf::RenderWindow* window);

    bool getKeyPressed(int n);
    bool getKeyDown(int n);
    float getValue(int n);

// void setKey(int n, sf::Keyboard::Key val);

// sf::Keyboard::Key getKey(int n);

    void update();

};

#endif // INPUT_H
