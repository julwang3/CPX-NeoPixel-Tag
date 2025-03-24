#include "Game.h"

#define COLORS 5 // Maximum depth of color an item can have
#define DURATION 2000 // Time it takes to collect all the items (ms)

/**
 * @brief NeoPixel locations the items can spawn
 */
const int ITEM_PIXELS[ITEMS] = {3, 1, 8, 6};

/**
 * @brief Capacitative touch pads associated with each NeoPixel location in
 * ITEM_PIXELS 
 * 
 * (e.g. Item at NeoPixel location 3 can be pixed up on capacitative touch 
 * pads 0 and 1.)
 */
const int ITEM_CAPTOUCH[ITEMS][2] = {
    {0, 1},
    {2, 3},
    {9, 10},
    {6, -1} // Only one capacitative touch pad (-1 = No pad)
};

/**
 * @brief Color gradient indicating gradual collection of an item
 */
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
    /**
     * @brief Initialize a new Item and its local variables
     */
    Item();

    /**
     * @brief Checks if item is collected given the player has continued collecting
     * it for an elapsed duration
     * 
     * @param elapsed_duration Time elapsed (ms)
     * @return true Item is collected by player
     * @return false Item has not been collected
     */
    bool Collect(float elapsed_duration);

    /**
     * @brief Return the current NeoPixel index the Item is on
     * 
     * @return const int NeoPixel index the Item is on
     */
    const int GetPixel() { return ITEM_PIXELS[_pixel_index]; }

    /**
     * @brief Return the capacitative touch pads that can be used to collect the Item
     * 
     * @return const int* List of capacitative touch pads
     */
    const int* GetCapTouch() { return ITEM_CAPTOUCH[_pixel_index]; }

    /**
     * @brief Return the current color of the object indicating how much longer the
     * player needs to collect the object
     * 
     * @return const Color Color of the item
     */
    const Color GetColor();

private:
    /**
     * @brief Updates the pixel the Item is on
     */
    void NewPixel();

    int _pixel_index;
    int _duration;
};
