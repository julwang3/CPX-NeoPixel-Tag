#ifndef GAME
#define GAME

#define PIXELS 12
#define PIXELS_DISPLAY 10
#define PIXEL_LEFT_START 5
#define PIXEL_RIGHT_START 4
#define ITEMS 4

// Enums
enum GameState
{
    START,
    PLAY,
    STOP
};

// Structs
struct Color 
{ 
    int R; int G; int B;

    Color(int r, int g, int b)
    {
        R = r; G = g; B = b;
    }
};

// Constants
const int PIXELS_CCLOCKWISE[PIXELS] = {0,1,2,3,4,11,5,6,7,8,9,10};

const Color COLOR_PLAYER(254, 254, 254);
const Color COLOR_ENEMY(255, 0, 0);

#endif
