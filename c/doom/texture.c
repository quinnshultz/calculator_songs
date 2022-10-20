// This module generates textures proceedingly for use in video games.
// Written by Quinn Shultz

#include <hpgcc49.h>
#include <hpgraphics.h>

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


    return image;
}

int main()
{
    hpg_set_mode_gray16(0); //enter 16 colour, single buffered mode
    hpg_clear(); //clear the screen

    hpg_t* image = main_menu();

    hpg_blit(image, 0, 0, 131, 80, hpg_stdscreen, 0, 0);
    while (!keyb_isON()); //wait until ON pressed
    
    hpg_free_image(image);
    return 0;
}
