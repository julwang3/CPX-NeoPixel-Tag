#include <math.h>
#include "Game.h"

#define TILT_LIMIT 8

class Player
{
public:
    /**
     * @brief Construct a new Player object
     */
    Player();

    /**
     * @brief Determines the NeoPixel position based on the tilt
     * of the CPX
     * 
     * @param x Acceleration of the CPX's tilt along the x-axis
     * @param y Acceleration of the CPX's tilt along the y-axis
     * @return int, The NeoPixel corresponding to the CPX's tilt
     */
    int Move(float x, float y);

private:
    /**
     * @brief Initializes _tilts array based on the TILT_LIMIT
     */
    void GeneratePixelTilts();

    /**
     * @brief 2D array containing the x- and y-tilt values associated
     * with each NeoPixel on the CPX
     */
    float _tilts[PIXELS][2];
};