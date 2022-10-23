# Doom
A first person shooter for the HP 49 series.

![alt text](https://raw.githubusercontent.com/quinnshultz/calculator_songs/main/doom/screenshot.jpg "A screenshot of the title menu.")

## Description
TI 83/84 owners can play Doom. Now HP 49/50 users can too!

## Compiling
Right now, the Makefile needs some changes to build complete recipes. A workaround is to build recipes separately so that dependencies are met.
```
make texture.o
make doom.o
make doom.hp
```

Ta Da! You should have a working executable. Move to the calculator stack and execute with the ARM Toolbox.

## Design Decisions
All assets are generated at runtime. This results in a smaller executable than can be achieved with stored assets.

## Authors
Written by Quinn Shultz.
