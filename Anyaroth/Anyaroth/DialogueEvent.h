#pragma once
#include "Event.h"
#include "DialoguePanel.h"

class DialogueEvent : public Event
{
private:
	Dialogue _dialogue = {};
	DialoguePanel* _dialoguePanel = nullptr;

public:
	DialogueEvent(DialoguePanel* dialoguePanel, Dialogue dialogue) : _dialogue(dialogue), _dialoguePanel(dialoguePanel) {}
	virtual ~DialogueEvent() {};

	virtual void update(double time);
	virtual void play();
};