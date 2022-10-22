#include <hpgcc49.h>

#include "player.h"

struct Weapon
{
	int capacity;
	int chambered;
	int damage;
};

struct Player
{
	Weapon w;
	int health;
};

extern Player* player_new()
{
	Player *p = malloc(sizeof(*p));
	if (!p) sat_stack_push_string("malloc() failed");
	// TODO: Player should start with a weapon
	p->health = 100;
	return p;
}

extern void player_health_set(Player *p, int health)
{
	p->health = health;
}

extern int player_health_get(Player *p)
{
	return p->health;
}
