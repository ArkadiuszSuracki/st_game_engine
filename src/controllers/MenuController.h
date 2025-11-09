#ifndef CONTROLLERS_MENU_CONTROLLER_H
#define CONTROLLERS_MENU_CONTROLLER_H

#include "controllers/BaseController.h"
#include "views/MenuView.h"
#include <vector>
#include <string>

enum class MenuAction {
	None,
	Play,
	Options,
	Exit
};

class MenuController : public BaseController
{
public:
	MenuController(Font uiFont);

	void Update() override;
	void Draw() override;

	MenuAction GetAction() const { return action; }
	void ClearAction() { action = MenuAction::None; }

private:
	MenuView view;
	std::vector<std::string> items;
	int selected;
	MenuAction action;
};

#endif
