#include <hpgcc49.h>

#include "player.h"

struct Player
{
	int ammo;
	int damage;

	int health;
};

extern Player* player_new()
{
	Player *p = malloc(sizeof(*p));
	if (!p) sat_stack_push_string("malloc() failed");
	p->ammo = 20;
	p->damage = 5;

	p->health = 100;
	return p;
}

extern void player_ammo_set(Player* p, int ammo)
{
	p->ammo = ammo;
}

extern int player_ammo_get(Player* p)
{
	return p->ammo;
}

extern void player_damage_set(Player* p, int damage)
{
	p->damage = damage;
}

extern int player_damage_get(Player* p)
{
	return p->damage;
}


extern void player_health_set(Player *p, int health)
{
	p->health = health;
}

extern int player_health_get(Player *p)
{
	return p->health;
}
