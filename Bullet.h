#pragma once
#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"


class Bullet :public Entity
{
public:

	Bullet(AnimationManager &a, Level &lev, int x, int y, bool dir) :Entity(a, x, y)
	{
		option("Bullet", 0.3, 10, "move");

		if (dir) dx = -0.3;
		obj = lev.GetObjects("solid");
	}

	void update(float time)
	{
		x += dx * time;

		for (int i = 0; i < obj.size(); i++)
			if (getRect().intersects(obj[i].rect))
			{
				Health = 0;
			}

		if (Health <= 0) {
			anim.set("explode"); dx = 0;
			if (anim.isPlaying() == false) life = false;
		}

		anim.tick(time);
	}

};

#endif BULLET_H
