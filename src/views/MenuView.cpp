#include "views/MenuView.h"

MenuView::MenuView(Font f) : font(f) {}

void MenuView::Draw(const std::vector<std::string> &items, int selected)
{
	float baseY = 200.0f;
	float x = 100.0f;
	float fontSize = 40.0f;

	for (int i = 0; i < (int)items.size(); ++i)
	{
		Color c = (i == selected) ? YELLOW : RAYWHITE;
		DrawTextEx(font, items[i].c_str(), { x, baseY + i * (fontSize + 10) }, fontSize, 1, c);
	}
}
