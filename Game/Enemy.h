#include "Game.h"

#define RUN_AWAY_SPEED_MULT 2

class Enemy
{
public:
    /**
     * @brief Defines the Enemy states
     */
    enum State
    {
        SPAWN,
        CHASE,
        RUN_AWAY,
        RUN_AWAY_COOLDOWN,
    };

    /**
     * @brief Default Enemy constructor
     */
    Enemy();

    /**
     * @brief Initializes a new Enemy
     * 
     * @param direction Direction the enemy is moving in
     * @param duration  Time between (ms) that defines the enemy speed
     * @param spawn_duration Delay from spawn before the enemy is active (ms)
     */
    Enemy(int direction, long duration, long spawn_duration);

    /**
     * @brief Spawns enemy and initialize its position
     */
    void Spawn();

    /**
     * @brief Updates the Enemy state and position, if appropriate, based on
     * the elapsed time in its state
     * 
     * @param player_pixel Player location
     * @param elapsed_duration Time elapsed (ms)
     * @return true Enemy collides with the player
     * @return false Enemy does not collide with the player
     */
    bool Update(int player_pixel, long elapsed_duration);

    /**
     * @brief Enemy is scared by player; Set Enemy state to RUN_AWAY
     */
    void Scare();

    /**
     * @brief Enemy is no longer scared; Set Enemy state to RUN_AWAY_COOLDOWN
     */
    void Chase();

    /**
     * @brief Return the current Pixel the enemy is on
     * 
     * @return const int Pixel index
     */
    const int GetPixel() { return _pixel; }

    /**
     * @brief Return whether the Enemy is active or not
     * 
     * @return true Enemy is active (not spawning in)
     * @return false Enemy is not active (spawning in)
     */
    const bool IsActive() { return _state != SPAWN; }

private:
    /**
     * @brief Update the position of the Enemy based on the player's
     * location and the state of the Enemy
     * 
     * @param player_pixel Player location
     */
    void Move(int player_pixel);

    /**
     * @brief Set the Enemy's state and updates local variables based
     * on the new state
     * 
     * @param state New enemy state
     */
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
