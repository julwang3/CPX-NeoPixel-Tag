#include "Audio.h"

const Audio _gameStart(262, 250);
const Audio _pickupItem(523, 100);
const Audio _spawnEnemy(131, 150);
const Audio _scareEnemy(988, 50);
const Audio _gameOver(123, 300);

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
