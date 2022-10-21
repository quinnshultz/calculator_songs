// This module generates textures proceedingly for use in video games.
// Written by Quinn Shultz

#include <hpgcc49.h>
#include <hpgraphics.h>

#include "texture.h"

hpg_t* main_menu()
{
    hpg_t* image = hpg_alloc_gray16_image(131, 80);
    hpg_clear_on(image);    // why u no give me a clean buffer?

    // Draw the DOOM logo
    hpg_set_color(image, HPG_COLOR_BLACK);
    hpg_draw_line_on(image, 18, 15, 40, 15);    // D
    hpg_draw_line_on(image, 40, 15, 43, 17);
    hpg_draw_line_on(image, 43, 17, 43, 48);
    hpg_draw_line_on(image, 43, 48, 44, 49);
    hpg_draw_line_on(image, 22, 65, 44, 49);
    hpg_draw_line_on(image, 22, 18, 22, 65);
    hpg_draw_line_on(image, 18, 15, 22, 18);

    hpg_draw_line_on(image, 30, 24, 35, 24);
    hpg_draw_line_on(image, 35, 24, 35, 42);
    hpg_draw_line_on(image, 30, 46, 35, 42);
    hpg_draw_line_on(image, 30, 24, 30, 46);

    hpg_draw_line_on(image, 45, 17, 48, 15);    // O
    hpg_draw_line_on(image, 48, 15, 62, 15);
    hpg_draw_line_on(image, 62, 15, 65, 17);
    hpg_draw_line_on(image, 65, 17, 65, 51);
    hpg_draw_line_on(image, 58, 57, 65, 51);
    hpg_draw_line_on(image, 45, 47, 58, 57);
    hpg_draw_line_on(image, 45, 17, 45, 47);

    hpg_draw_line_on(image, 52, 24, 57, 24);
    hpg_draw_line_on(image, 57, 24, 57, 46);
    hpg_draw_line_on(image, 52, 42, 57, 46);
    hpg_draw_line_on(image, 52, 24, 52, 42);

    hpg_draw_line_on(image, 67, 17, 70, 15);    // O
    hpg_draw_line_on(image, 70, 15, 84, 15);
    hpg_draw_line_on(image, 84, 15, 87, 17);
    hpg_draw_line_on(image, 87, 17, 87, 47);
    hpg_draw_line_on(image, 74, 57, 87, 47);
    hpg_draw_line_on(image, 67, 51, 74, 57);
    hpg_draw_line_on(image, 67, 17, 67, 51);

    hpg_draw_line_on(image, 74, 24, 79, 24);
    hpg_draw_line_on(image, 79, 24, 79, 42);
    hpg_draw_line_on(image, 74, 46, 79, 42);
    hpg_draw_line_on(image, 74, 24, 74, 46);

    hpg_draw_line_on(image, 89, 15, 96, 15);    // M
    hpg_draw_line_on(image, 96, 15, 99, 23);
    hpg_draw_line_on(image, 99, 23, 102, 15);
    hpg_draw_line_on(image, 102, 15, 114, 15);
    hpg_draw_line_on(image, 110, 18, 114, 15);
    hpg_draw_line_on(image, 110, 18, 110, 65);
    hpg_draw_line_on(image, 102, 59, 110, 65);
    hpg_draw_line_on(image, 102, 42, 102, 59);
    hpg_draw_line_on(image, 99, 51, 102, 42);
    hpg_draw_line_on(image, 97, 42, 99, 51);
    hpg_draw_line_on(image, 97, 42, 97, 55);
    hpg_draw_line_on(image, 88, 49, 97, 55);
    hpg_draw_line_on(image, 88, 49, 89, 48);
    hpg_draw_line_on(image, 89, 48, 89, 15);
    
    hpg_draw_text_on(image, "Play Game", 5, 70);
    hpg_draw_text_on(image, "Settings", 45, 70);
    hpg_draw_text_on(image, "About", 80, 70);
    hpg_draw_text_on(image, "Extras", 105, 70);

    return image;
}

hpg_t* main_menu_cursor() 
{
    hpg_t* image = hpg_alloc_gray16_image(16, 16);
    hpg_clear_on(image);

    // Draw a pentagram
    hpg_draw_circle_on(image, 8, 8, 7);

    hpg_draw_line_on(image, 3, 1, 14, 10);
    hpg_draw_line_on(image, 1, 10, 14, 10);
    hpg_draw_line_on(image, 3, 1, 7, 15);
    hpg_draw_line_on(image, 1, 10, 11, 1);
    hpg_draw_line_on(image, 11, 1, 7, 15);
    return image;
}

hpg_t* draw_hud()
{
    hpg_t* image = hpg_alloc_gray16_image(131, 80);
    hpg_clear_on(image);

    return image;
}

// TODO: Move to "doom.c"
int play_game()
{
    sys_slowOff();  // Run the game at full system speed

    hpg_set_mode_gray16(0);
    hpg_clear();

    // Main gameplay loop
    while (!keyb_isON());

    sys_slowOn();   // Save batteries in the main menu
    return 0;
}

// TODO: Move to "doom.c"
int main()
{
    hpg_set_mode_gray16(0); //enter 16 colour, single buffered mode
    hpg_clear(); //clear the screen

    enum menu_items{play,settings,about,extras};
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
