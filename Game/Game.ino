#include <Adafruit_CircuitPlayground.h>
#include "Player.h"
#include "Item.h"
#include "Enemy.h"
#include "Audio.h"

#define NEOPIXEL_BRIGHTNESS 3
#define ENEMIES 2
#define ACCEL_TILT_LIMIT 8
#define CAP_TOUCH_THRESHOLD 900
#define SCREAM_THRESHOLD 65
#define START_SCREEN_COLORS 5

GameState _state;
Player _player;
Item _item;
Enemy _enemy[ENEMIES] = {
    Enemy(1, 750, 10000),
    Enemy(-1, 500, 30000),
};
AudioPlayer _audioPlayer;

bool _prev_is_start;
int _prev_player_pixel;
unsigned long _prev_millis;
bool _prev_is_scream;
bool _prev_enemy_active[ENEMIES] = {
    false,
    false,
};

void setup() 
{   
    // Initialize circuit playground
    CircuitPlayground.begin();
    Serial.begin(9600);

    // Set NeoPixel brightness
    CircuitPlayground.setBrightness(NEOPIXEL_BRIGHTNESS);

    // Initialize variables
    _state = START;
    _prev_is_start = CircuitPlayground.slideSwitch();
    _prev_millis = millis(); 
    _prev_is_scream = false;
}

void loop()
{
    bool is_start = CircuitPlayground.slideSwitch();
    unsigned long current_millis = millis();
    unsigned long millis_difference = current_millis - _prev_millis;
    
    if (_state == START)
    {
        // Check if player started game
        if (is_start != _prev_is_start)
        {
            update_state(PLAY);
        }
        // Display starting screen
        else
        {
            CircuitPlayground.clearPixels();
            for (int i = 0; i < PIXELS; i++)
            {
                draw_pixel(i, COLOR_ITEMS[i % COLORS]);
            }
        }
    }
    else if (_state == PLAY)
    {
        // Get sensor input
        // Accelerometer
        float x = CircuitPlayground.motionX();
        float y = CircuitPlayground.motionY();
        float z = CircuitPlayground.motionZ();
        // Capacitative Touch
        bool is_item_touch = false;
        const int* item_captouch = _item.GetCapTouch();
        for (int i = 0; i < 2; i++)
        {
            if (item_captouch[i] != -1)
            {
                is_item_touch |= (CircuitPlayground.readCap(item_captouch[i]) > CAP_TOUCH_THRESHOLD);
            }
        }
        // Scream
        bool is_scream = CircuitPlayground.mic.soundPressureLevel(10) > SCREAM_THRESHOLD;
        Serial.println(CircuitPlayground.mic.soundPressureLevel(10)); // TODO: Delete

        // Move player
        int player_pixel = _player.Move(x, y);

        // Check if player picked up item
        if (is_item_touch && player_pixel == _item.GetPixel())
        {
            bool is_collected = _item.Collect(millis_difference);
            if (is_collected)
            {
                play_audio(_audioPlayer.PickupItem());
            }
        }

        // Move enemy
        bool collide = false;
        for (int i = 0; i < ENEMIES; i++)
        {
            bool is_active = _enemy[i].IsActive();
            if (is_active)
            {
                // Just spawned
                if (!_prev_enemy_active[i])
                {
                    play_audio(_audioPlayer.SpawnEnemy());
                }
                // Scare enemy
                if (is_scream & !_prev_is_scream)
                {
                    _enemy[i].Scare();
                    play_audio(_audioPlayer.ScareEnemy());
                }
                if (!is_scream & _prev_is_scream)
                {
                    _enemy[i].Chase();
                }
            }
            collide |= _enemy[i].Update(player_pixel, millis_difference);
            _prev_enemy_active[i] = is_active;
        }
        // Check player collision with enemy
        if (collide)
        {
            update_state(STOP);
            return;
        }

        // Draw pixels
        CircuitPlayground.clearPixels();
        draw_pixel(player_pixel, COLOR_PLAYER);
        draw_pixel(_item.GetPixel(), _item.GetColor());
        for (int i = 0; i < ENEMIES; i++)
        {
            if (_enemy[i].IsActive())
            {
                draw_pixel(_enemy[i].GetPixel(), COLOR_ENEMY);
            }
        }

        _prev_is_scream = is_scream;
    }
    else if (_state == STOP)
    {
        // Check if player restarted game
        if (CircuitPlayground.leftButton() | CircuitPlayground.rightButton())
        {
            update_state(START);
        }
        // Display stop screen
        else
        {
            CircuitPlayground.clearPixels();
            for (int i = 0; i < PIXELS; i++)
            {
                draw_pixel(i, COLOR_ENEMY);
            }
        }
    }

    _prev_is_start = is_start;
    _prev_millis = current_millis;
}

void draw_pixel(int pixel, const Color color)
{
    if (pixel >= 0 && pixel <= 9)
    {
        CircuitPlayground.setPixelColor(pixel, color.R, color.G, color.B);
    }
}

void update_state(GameState state)
{
    if (state == PLAY)
    {
        for (int i = 0; i < ENEMIES; i++)
        {
            _enemy[i].Spawn();
        }
        
        play_audio(_audioPlayer.GameStart());
    }
    else if (state == STOP)
    {
        play_audio(_audioPlayer.GameOver());
    }
    _state = state;
}

void play_audio(const Audio audio)
{
    if (audio.Duration > 0)
    {
        CircuitPlayground.playTone(audio.Note, audio.Duration);
    }
}
