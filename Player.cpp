#include "Player.h"

Player::Player()
{
    GeneratePixelTilts();
}

int Player::Move(float x, float y)
{
    int pixel = 0;
    float min_distance = 3 * TILT_LIMIT;
    // Identify NeoPixel closest to given xy tilt values
    for (int i = 0; i < (PIXELS - 1); i++) // Ignore enemy base (11)
    {
        float x_dist = x - _tilts[i][0];
        float y_dist = y - _tilts[i][1];
        float distance = sqrt(pow(x_dist, 2) + pow(y_dist, 2));
        
        // Update min distance
        if (distance < min_distance)
        {
            pixel = i;
            min_distance = distance;
        }
    }
    return pixel;
}

void Player::GeneratePixelTilts()
{
    float increments = TILT_LIMIT / 3.0;
      
    float x = increments;
    float y = -2.0 * increments;
    float x_dir = 1;
    float y_dir = 1;
    for (int i = 0; i < PIXELS; i++) 
    {
        // Set pixel tilts value
        int pixel = PIXELS_CCLOCKWISE[i];
        _tilts[pixel][0] = x;
        _tilts[pixel][1] = y;
        
        // Updating xy values
        x += (increments * x_dir);
        y += (increments * y_dir);
        if ((int)x > TILT_LIMIT) 
        {
            x = TILT_LIMIT - increments;
            x_dir *= -1;
        }
        else if ((int)x < -TILT_LIMIT)
        {
            x = -TILT_LIMIT + increments;
            x_dir *= -1;
        }
        if ((int)y > TILT_LIMIT) 
        {
            y = TILT_LIMIT - increments;
            y_dir *= -1;
        }
    }
}
