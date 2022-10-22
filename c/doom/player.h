// The module represents the player (health, equipped weapon, etc.)
// Written by Quinn Shultz
#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct Player Player;
typedef struct Weapon Weapon;

extern Player* player_new();

extern void player_health_set(Player *p, int health);
extern int player_health_get(Player *p);

#endif
