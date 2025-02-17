#include <bits/stdc++.h>
#include "Item.h"

Item::Item()
{
    srand(time(0));
    _pixel_index = rand() % ITEMS;
    _duration = DURATION;
}

bool Item::Collect(float millis)
{
    _duration -= millis;
    if (_duration <= 0)
    {
        NewPixel();
        return true;
    }
    return false;
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

const Color Item::GetColor()
{
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
