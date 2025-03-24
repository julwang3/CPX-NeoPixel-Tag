#include <bits/stdc++.h>
#include "Item.h"

Item::Item()
{
    // Randomize item placement
    srand(time(0));

    // Initialize local variables
    _pixel_index = rand() % ITEMS;
    _duration = DURATION;
}

bool Item::Collect(float elapsed_duration)
{
    _duration -= elapsed_duration;
    if (_duration <= 0)
    {
        // Collected
        NewPixel();
        return true;
    }
    return false;
}

const Color Item::GetColor()
{
    // Determine Item color based on the remaning duration
    unsigned long increments = DURATION / COLORS;
    for (int i = 0; i < COLORS; i++)
    {
        if (_duration <= (increments * (i + 1)))
        {
            return COLOR_ITEMS[i];
        }
    }
    return COLOR_ITEMS[COLORS - 1];
}

void Item::NewPixel()
{
    // Pixel
    int index = rand() % ITEMS;
    while (index == _pixel_index)
    {
        index = rand() % ITEMS;
    }
    _pixel_index = index;
    
    // Duration
    int duration_increments = rand() % COLORS + 1;
    int increments = DURATION / COLORS;
    _duration = duration_increments * increments;
}
