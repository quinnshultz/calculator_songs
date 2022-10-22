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

hpg_t* health_hud(int health)
{
    hpg_t* image = hpg_alloc_mono_image(27, 16);
    char c[4];  // Buffer to hold the player's health
    sprintf(c, "%d", health);
    hpg_clear_on(image);

    hpg_draw_rect_on(image, 0, 0, 26, 15);
    hpg_draw_text_on(image, "Health", 2, 2);
    hpg_draw_text_on(image, c, 8, 8);

    return image;
}

hpg_t* ammo_hud(int ammo)
{
    hpg_t* image = hpg_alloc_mono_image(26, 16);
    char c[4];
    sprintf(c, "%d", ammo);
    hpg_clear_on(image);

    hpg_draw_rect_on(image, 0, 0, 25, 15);
    hpg_draw_text_on(image, "Ammo", 6, 2);
    hpg_draw_text_on(image, c, 10, 8);

    return image;
}

hpg_t* player_pistol()
{
    hpg_t* image = hpg_alloc_gray16_image(20, 20);
    hpg_clear_on(image);

    // Gun
    hpg_set_color(image, HPG_COLOR_GRAY_14);
    hpg_fill_rect_on(image, 8, 3, 10, 5);
    hpg_fill_rect_on(image, 8, 0, 10, 2);
    hpg_set_color(image, HPG_COLOR_GRAY_10);
    hpg_fill_rect_on(image, 7, 2, 11, 6);

    // Hand
    hpg_set_color(image, HPG_COLOR_GRAY_6);
    hpg_fill_circle_on(image, 9, 7, 4);

    return image;
}
