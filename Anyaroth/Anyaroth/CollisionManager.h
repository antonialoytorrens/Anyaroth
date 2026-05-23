#pragma once
#include <list>
#include <vector>
#include <box2d/box2d.h>

class CollisionManager : public b2ContactListener
{
public:
	virtual ~CollisionManager() {}
	using b2ContactListener::PreSolve;
	using b2ContactListener::PostSolve;
	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
	void PreSolve(b2Contact* contact);
	void PostSolve(b2Contact* contact);
};
