#include <bits/stdc++.h>
#include "Enemy.h"

Enemy::Enemy()
{
    Enemy(1, 500, 5000);
}

Enemy::Enemy(int direction, long duration, long spawn_duration)
{
    _direction = direction;
    _duration = duration;
    _spawn_duration = spawn_duration;

    Spawn();
}

void Enemy::Spawn()
{
    // Set spawn location based on movement direction
    if (_direction == 1)
    {
        _pixel = PIXEL_RIGHT_START;
    }
    else if (_direction == -1)
    {
        _pixel = PIXEL_LEFT_START;
    }
    
    // Initialize in SPAWN state
    _current_duration = _spawn_duration;
    _state = SPAWN;
}

bool Enemy::Update(int player_pixel, long elapsed_duration)
{
    _current_duration -= elapsed_duration;

    if (_state == SPAWN)
    {
        // Set active
        if (_current_duration <= 0)
        {
            SetState(CHASE);
        }
        return false;
    }
    else 
    {
        // Run away cooldown
        if (_state == RUN_AWAY_COOLDOWN)
        {
            _cooldown_duration -= elapsed_duration;
            if (_cooldown_duration <= 0)
            {
                SetState(CHASE);
            }
        }
        // Move
        if (_current_duration <= 0)
        {
            Move(player_pixel);
            if (_state == CHASE)
            {
                _current_duration = _duration;
            }
            else
            {
                _current_duration = _run_away_duration;
            }
        }
        return _pixel == player_pixel;
    }
}

void Enemy::Scare()
{
    if (_state != SPAWN)
    {
        SetState(RUN_AWAY);
    }
}

void Enemy::Chase()
{
    if (_state != SPAWN)
    {
        SetState(RUN_AWAY_COOLDOWN);
    }
}

void Enemy::Move(int player_pixel)
{
    if (_pixel == player_pixel)
    {
        return;
    }

    // Identify move direction
    int distance = player_pixel - _pixel;
    if (_state == CHASE)
    {
        // Chase after the player
        if (distance > 0)
        {
            _direction = (distance < (PIXELS_DISPLAY / 2)) ? 1 : -1;
        }
        else if (distance < 0)
        {
            _direction = (distance < -(PIXELS_DISPLAY / 2)) ? 1 : -1;
        }
    }
    else if (_state == RUN_AWAY | _state == RUN_AWAY_COOLDOWN)
    {
        // Run away from the player
        if (distance > 0)
        {
            _direction = (distance < (PIXELS_DISPLAY / 2)) ? -1 : 1;
        }
        else if (distance < 0)
        {
            _direction = (distance < -(PIXELS_DISPLAY / 2)) ? -1 : 1;
        }
    }

    // Update pixel position
    _pixel = (_pixel + _direction) % PIXELS_DISPLAY;
    if (_pixel < 0)
    {
        _pixel += PIXELS_DISPLAY;
    }
}

void Enemy::SetState(State state)
{
    // Update duration (and direction) based on state
    if (_state == SPAWN & state == CHASE)
    {
        _current_duration = _duration;
        _run_away_duration = _duration;
    }
    else
    {
        if (state == CHASE)
        {
            _run_away_duration = _duration;
            _cooldown_duration = 0;
        }
        else if (state == RUN_AWAY)
        {
            _run_away_duration /= RUN_AWAY_SPEED_MULT;
        }
        else if (state == RUN_AWAY_COOLDOWN)
        {
            _cooldown_duration = _run_away_duration * 4;
        }
        _current_duration = _run_away_duration;
        _direction *= -1;
    }
    // Update state
    _state = state;
}
