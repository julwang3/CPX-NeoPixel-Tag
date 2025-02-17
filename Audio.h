#include "Game.h"

#ifndef AUDIO_PLAYER
#define AUDIO_PLAYER

//// TODO START - Complex audio/melody class
//struct Melody
//{
//    int Size;
//    int* Notes;
//    int* Duration;
//
//    Melody()
//    {
//        Size = 0;
//        Notes = nullptr;
//        Duration = nullptr;
//    }
//    
//    Melody(int size, int notes[], int duration[])
//    {
//        Size = size;
//        Notes = new int[Size];
//        Duration = new int[Size];
//
//        for (int i = 0; i < Size; i++)
//        {
//            Notes[i] = notes[i];
//            Duration[i] = duration[i];
//        }
//    }
//
//    ~Melody()
//    {
//        delete[] Notes;
//        delete[] Duration;
//    }
//};
//// TODO END

class AudioPlayer
{
public:
    AudioPlayer();

    const Audio GameStart();
    const Audio PickupItem();
    const Audio SpawnEnemy();
    const Audio ScareEnemy();
    const Audio GameOver();

//private:
    // Melody _gameStart;
    // Melody _pickupItem;
    // Melody _spawnEnemy;
    // Melody _scareEnemy;
    // Melody _gameOver;
};

#endif
