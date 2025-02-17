#include <Adafruit_CircuitPlayground.h>
#include "Audio.h"

#define AUDIO_DURATION 100

// TODO
//const Audio _gameStart;
//const Audio _pickupItem;
//const Audio _spawnEnemy;
//const Audio _scareEnemy;
//const Audio _gameOver;

void AudioPlayer::GameStart()
{
//    PlayAudio(_gameStart);
}

void AudioPlayer::PickupItem()
{
//    PlayAudio(_pickupItem);
}

void AudioPlayer::SpawnEnemy()
{
//    PlayAudio(_spawnEnemy);
}

void AudioPlayer::ScareEnemy()
{
//    PlayAudio(_scareEnemy);
}

void AudioPlayer::GameOver()
{
//    PlayAudio(_gameOver);
}

void AudioPlayer::PlayAudio(const Audio audio)
{
    for (int i = 0; i < audio.Size; i++)
    {
        CircuitPlayground.playTone(audio.Notes[i], 100);
    }
}
