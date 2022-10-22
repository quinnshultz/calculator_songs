// The module represents the player (health, equipped weapon, etc.)
// Written by Quinn Shultz
#ifndef _PLAYER_H_
#define _PLAYER_H_

typedef struct Player Player;

extern Player* player_new();

extern void player_health_set(Player *p, int health);
extern int player_health_get(Player *p);

extern void player_ammo_set(Player *p, int ammo);
extern int player_ammo_get(Player *p);

// Weapon damage
extern void player_damage_set(Player *p, int damage);
extern int player_health_get(Player *p);

#endif
