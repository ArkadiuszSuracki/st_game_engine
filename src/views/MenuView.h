#ifndef VIEWS_MENU_VIEW_H
#define VIEWS_MENU_VIEW_H

#include "raylib.h"
#include <vector>
#include <string>

class MenuView
{
public:
	MenuView(Font font);

	void Draw(const std::vector<std::string> &items, int selected);

private:
	Font font;
};

#endif
