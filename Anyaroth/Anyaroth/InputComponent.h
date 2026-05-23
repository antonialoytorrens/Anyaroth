#pragma once
#include "Component.h"

class GameObject;
union SDL_Event;

class InputComponent : public Component
{
public:
	InputComponent(GameObject* obj);
	virtual ~InputComponent() {}
	virtual void handleEvent(const SDL_Event& event) = 0;
};