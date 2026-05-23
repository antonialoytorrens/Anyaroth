#pragma once

class Component
{
public:
	Component() {}
	virtual ~Component() = 0;
};

inline Component::~Component() {}
