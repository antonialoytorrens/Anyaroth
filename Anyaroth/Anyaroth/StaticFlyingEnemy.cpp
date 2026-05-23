#include "StaticFlyingEnemy.h"
#include "AnimatedSpriteComponent.h"
#include "BodyComponent.h"

StaticFlyingEnemy::StaticFlyingEnemy(Game* g, Player* player, Vector2D pos, BulletPool* pool) : Enemy(g, player, pos, g->getTexture("AirTurret"), "turretDeath", "turretHit"), DistanceStaticEnemy( g,  player,  pos,  pool)
{
	_body->getBody()->SetGravityScale(0);
	_hurtParticle = g->getTexture("Sparks");
}