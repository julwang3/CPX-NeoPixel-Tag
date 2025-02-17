#include "Game.h"

#define RUN_AWAY_SPEED_MULT 2

class Enemy
{
public:
    enum State
    {
        SPAWN,
        CHASE,
        RUN_AWAY,
        RUN_AWAY_COOLDOWN,
    };

    Enemy();
    Enemy(int direction, long duration, long spawn_duration);

    void Spawn();
    bool Update(int player_pixel, long elapsed_duration);
    void Scare();
    void Chase();

    const int GetPixel() { return _pixel; }
    const long GetDuration() { return _duration; }
    const bool IsActive() { return _state != SPAWN; }
    const State GetState() { return _state; }
    const long GetCurrentDuration() { return _current_duration; }

private:
    void Move(int player_pixel);
    void SetState(State state);
    
    State _state;
    int _pixel;
    int _direction;
    long _duration;
    long _spawn_duration;
    long _current_duration;
    long _run_away_duration;
    long _cooldown_duration;
};
