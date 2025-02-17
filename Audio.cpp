#include "Audio.h"

#define AUDIO_DURATION 100

const Audio _gameStart(262, 250);
const Audio _pickupItem(523, 100);
const Audio _spawnEnemy(131, 150);
const Audio _scareEnemy(988, 50);
const Audio _gameOver(123, 300);

AudioPlayer::AudioPlayer()
{
    // int gameStartNotes[] = {523, 784, 1046};
    // int gameStartDuration[] = {100, 100, 300};
    // _gameStart = Melody(3, gameStartNotes, gameStartDuration);

    // int pickupItemNotes[] = {523, 1046};
    // int pickupItemDuration[] = {100, 200};
    // _pickupItem = Melody(2, pickupItemNotes, pickupItemDuration);

    // int spawnEnemNotes[] = {123};
    // int spawnEnemDuration[] = {100};
    // _spawnEnemy = Melody(1, spawnEnemNotes, spawnEnemDuration);

    // int scareEnemyNotes[] = {988};
    // int scareEnemyDuration[] = {250};
    // _scareEnemy = Melody(1, scareEnemyNotes, scareEnemyDuration);

    // int gameOverNotes[] = {262, 196, 131};
    // int gameOverDuration[] = {100, 100, 300};
    // _gameOver = Melody(3, gameOverNotes, gameOverDuration);
}

const Audio AudioPlayer::GameStart()
{
   return _gameStart;
}

const Audio AudioPlayer::PickupItem()
{
    return _pickupItem;
}

const Audio AudioPlayer::SpawnEnemy()
{
    return _spawnEnemy;
}

const Audio AudioPlayer::ScareEnemy()
{
    return _scareEnemy;
}

const Audio AudioPlayer::GameOver()
{
    return _gameOver;
}
