#include "Game.h"

#ifndef AUDIO_PLAYER
#define AUDIO_PLAYER

#define AUDIO_DURATION 100

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
