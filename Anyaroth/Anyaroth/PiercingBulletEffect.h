#pragma once
#include "BulletEffect.h"
class PiercingBulletEffect :
	public BulletEffect
{
public:
	PiercingBulletEffect();
	virtual ~PiercingBulletEffect();

	virtual void beginCollision(Bullet* bullet, GameObject* other, b2Contact* contact);
	virtual void update(Bullet* bullet, double time);
	virtual void init(Bullet* bullet);
};

