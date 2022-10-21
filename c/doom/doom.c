// Doom for HP50G
// Written by Quinn Shultz

#include <hpgcc49.h>
#include <hpgraphics.h>

#include "texture.h"

int play_game()
{
    sys_slowOff();  // Run the game at full system speed

    hpg_set_mode_gray16(0);
    hpg_clear();

    // Initialize HUD with some hardcoded values (just for fun)
    hpg_t* hh = health_hud(100);
    hpg_t* ah = ammo_hud(20);

    hpg_blit(hh, 0, 0, 25, 15, hpg_stdscreen, 0, 65);
    hpg_blit(ah, 0, 0, 25, 15, hpg_stdscreen, 105, 65);

    // Main gameplay loop
    while (!keyb_isON());

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
