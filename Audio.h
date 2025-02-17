#ifndef AUDIO_PLAYER
#define AUDIO_PLAYER

struct Audio
{
    int Size;
    int* Notes;

    Audio();
    Audio(int size, int* notes)
    {
        Size = size;
        Notes = notes;
    }
};

class AudioPlayer
{
public:
    void GameStart();
    void PickupItem();
    void SpawnEnemy(); // TODO
    void ScareEnemy();
    void GameOver();

private:
    void PlayAudio(const Audio audio);
};

#endif
