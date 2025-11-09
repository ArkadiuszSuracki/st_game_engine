#ifndef CONTROLLERS_OPTIONS_CONTROLLER_H
#define CONTROLLERS_OPTIONS_CONTROLLER_H

#include "controllers/BaseController.h"
#include "views/OptionsView.h"

enum class OptionsAction {
	None,
	Back
};

class OptionsController : public BaseController
{
public:
	OptionsController(Font uiFont);

	void Update() override;
	void Draw() override;

	OptionsAction GetAction() const { return action; }
	void ClearAction() { action = OptionsAction::None; }

	bool IsFullscreen() const { return fullscreen; }

private:
	OptionsView view;
	int selected;
	bool fullscreen;
	OptionsAction action;
};

#endif

