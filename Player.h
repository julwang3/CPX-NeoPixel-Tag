#include <math.h>
#include "Game.h"

#define TILT_LIMIT 8

class Player
{
public:
    Player();

    int Move(float x, float y);
    
    const int GetPixel();

private:
    void _GeneratePixelTilts();

    float _tilts[PIXELS][2];
    int _pixel;
};