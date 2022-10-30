// Doom for HP50G
// Written by Quinn Shultz

#include <hpgcc49.h>
#include <hpgraphics.h>

#include "texture.h"
#include "player.h"

int play_game()
{
    sys_slowOff();  // Run the game at full system speed

    hpg_set_mode_gray16(0);
    hpg_clear();
    Player *p = player_new();

    // Initialize HUD
    hpg_t* hh = health_hud(player_health_get(p));
    hpg_t* ah = ammo_hud(player_ammo_get(p));

    hpg_t* player_image = player_pistol();
    hpg_t* player_image_firing = player_pistol_firing();

    hpg_blit(hh, 0, 0, 27, 16, hpg_stdscreen, 0, 65);
    hpg_blit(ah, 0, 0, 26, 16, hpg_stdscreen, 105, 65);
    hpg_blit(player_image, 0, 0, 20, 20, hpg_stdscreen, 55, 60);

    int time_passed = 0;
    int delta_time = 0;

    // Main gameplay loop
    while (!keyb_isON())
    {
        // If "I" (TOOL) key is pressed
        if (keyb_isKeyPressed(6, 5))
        {
            keyb_waitKeyPressed();
            hpg_free_image(ah);
            ah = ammo_hud(fire(p));
            hpg_blit(ah, 0, 0, 26, 16, hpg_stdscreen, 105, 65);
            hpg_blit(player_image_firing, 0, 0, 20, 20, hpg_stdscreen, 55, 60);
            hpg_blit(player_image, 0, 0, 20, 20, hpg_stdscreen, 55, 60);
        }

        // If "Up Arrow" key is pressed
        if (keyb_isUp())
        {
            set_moving_forward(p, 1);
        }
        else if (keyb_isDown())
        {
            set_moving_backward(p, 1);
        }
        else if (keyb_isLeft())
        {
            set_moving_left(p, 1);
        }
        else if (keyb_isRight())
        {
            set_moving_right(p, 1);
        }

        // Update game logic once for every tick passed
        while (time_passed >= 1) {
            time_passed -= 1;
        }

        delta_time = sys_isRTCTick();
        time_passed += delta_time;
    }

    hpg_free_image(hh);
    hpg_free_image(ah);
    hpg_free_image(player_image);
    hpg_free_image(player_image_firing);

    free(p);
    sys_slowOn();   // Save batteries in the main menu
    return 0;
}

int main()
{
    hpg_set_mode_gray16(0);
    hpg_clear(); //clear the screen

    enum menu_items { play, settings, about, extras };
    enum menu_items selection = play;

    hpg_t* background = main_menu();
    hpg_t* cursor = main_menu_cursor();

    hpg_blit(background, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
    hpg_blit(cursor, 0, 0, 16, 16, hpg_stdscreen, 10, 65);
    while (!keyb_isON())
    {
        if (keyb_isLeft() && selection > 0)
        {
            selection--;
            // Is it really necessary to redraw the whole screen every time?
            hpg_clear();
            hpg_blit(background, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
            hpg_blit(cursor, 0, 0, 16, 16, hpg_stdscreen, (35 * selection) + 10, 65);
        }
        else if (keyb_isLeft())
        {
            selection = extras;
            hpg_clear();
            hpg_blit(background, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
            hpg_blit(cursor, 0, 0, 16, 16, hpg_stdscreen, (35 * selection) + 10, 65);
        }
        if (keyb_isRight() && selection < 3)
        {
            selection++;
            hpg_clear();
            hpg_blit(background, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
            hpg_blit(cursor, 0, 0, 16, 16, hpg_stdscreen, (35 * selection) + 10, 65);
        }
        else if (keyb_isRight())
        {
            selection = play;
            hpg_clear();
            hpg_blit(background, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
            hpg_blit(cursor, 0, 0, 16, 16, hpg_stdscreen, (35 * selection) + 10, 65);
        }

        // User makes a selection with the "ENTER" key
        if (keyb_isKeyPressed(0, 6))
        {
            switch (selection) {
            case play:
                hpg_free_image(background);
                hpg_free_image(cursor);
                play_game();
                break;
            case settings:
                sat_stack_push_string("Settings");
                break;
            case about:
                sat_stack_push_string("About");
                break;
            case extras:
                sat_stack_push_string("Extras");
                break;
            }

        }


    }
    hpg_free_image(cursor);
    hpg_free_image(background);
    return 0;
}
