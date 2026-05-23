#pragma once
#include "Event.h"

class ChangeLevelEvent : public Event
{
public:
	ChangeLevelEvent() {}
	virtual ~ChangeLevelEvent() {};

	virtual void play();
	virtual void update(double /*deltaTime*/) {}
};