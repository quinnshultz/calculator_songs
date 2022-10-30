#include <hpgcc49.h>

#include "player.h"

struct Player
{
	int ammo;
	int damage;

	int health;

	int movingForward;
	int movingBackward;
	int movingLeft;
	int movingRight;
};

extern Player* player_new()
{
	Player *p = malloc(sizeof(*p));
	if (!p) sat_stack_push_string("malloc() failed");
	p->ammo = 20;
	p->damage = 5;

	p->health = 100;
	p->movingForward = 0;
	p->movingBackward = 0;
	p->movingLeft = 0;
	p->movingRight = 0;
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

extern int fire(Player* p)
{
	if (p->ammo > 0)
	{
		p->ammo--;
	}
	return p->ammo;
}

extern void player_health_set(Player *p, int health)
{
	p->health = health;
}

extern int player_health_get(Player *p)
{
	return p->health;
}

extern void set_moving_forward(Player* p, int moving)
{
	p->movingForward = moving;
}

extern int get_moving_forward(Player* p)
{
	return p->movingForward;
}

extern void set_moving_backward(Player* p, int moving)
{
	p->movingBackward = moving;
}

extern int get_moving_backward(Player* p)
{
	return p->movingBackward;
}

extern void set_moving_left(Player* p, int moving)
{
	p->movingLeft = moving;
}

extern int get_moving_left(Player* p)
{
	return p->movingLeft;
}

extern void set_moving_right(Player* p, int moving)
{
	p->movingRight = moving;
}

extern int get_moving_right(Player* p)
{
	return p->movingRight;
}
