#include "Game.h"

#ifndef AUDIO_PLAYER
#define AUDIO_PLAYER

#define AUDIO_DURATION 100

struct Audio
{
    int Note;
    int Duration;
    
    Audio(int note, int duration)
    {
        Note = note;
        Duration = duration;
    }
};

const Audio GAME_START(262, 250);
const Audio PICKUP_ITEM(523, 100);
const Audio SPAWN_ENEMY(131, 150);
const Audio SCARE_ENEMY(988, 50);
const Audio GAME_OVER(123, 300);

class AudioPlayer
{
public:
    // All functions below return an Audio (frequency and duration) corresponding
    // to the specified action
    
    const Audio GameStart();
    const Audio PickupItem();
    const Audio SpawnEnemy();
    const Audio ScareEnemy();
    const Audio GameOver();
};

#endif
