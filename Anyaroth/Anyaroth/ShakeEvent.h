#pragma once
#include "Event.h"
#include "Camera.h"

class ShakeEvent : public Event
{
private:
	int _time, _timeOnEvent = 0;
	int _intensity;
	Camera* _cam;

public:
	ShakeEvent(Camera* cam, int time, int intesity) : _time(time), _intensity(intesity), _cam(cam) {}
	virtual ~ShakeEvent() {};

	virtual void update(double time);
	virtual void play();
};