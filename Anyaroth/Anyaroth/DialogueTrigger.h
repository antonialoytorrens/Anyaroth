#pragma once
#include "Trigger.h"
#include "PlayStateHUD.h"

class DialogueTrigger :
	public Trigger
{
public:
	DialogueTrigger(Game* game, string data, Player* player, int xPos = 0, int yPos = 0);
	virtual ~DialogueTrigger();

	PlayStateHUD* getPlayHUD();
};

