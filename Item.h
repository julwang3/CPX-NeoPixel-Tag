#include "Game.h"

#define COLORS 5
#define DURATION 2000

const int ITEM_PIXELS[ITEMS] = {3, 1, 8, 6};
const int ITEM_CAPTOUCH[ITEMS][2] = {
    {0, 1},
    {2, 3},
    {9, 10},
    {6, -1} // Only one capacitative touch pad
};

const Color COLOR_ITEMS[COLORS] = {
    Color(60, 255, 0),
    Color(0, 255, 50),
    Color(0, 225, 200),
    Color(0, 90, 255),
    Color(0, 60, 255),
};

class Item
{
public:
    Item();

    void Collect(float millis);

    const int GetPixel() { return ITEM_PIXELS[_pixel_index]; }
    const int* GetCapTouch() { return ITEM_CAPTOUCH[_pixel_index]; }
    const Color GetColor();

private:
    void NewPixel();

    int _pixel_index;
    int _duration;
};
