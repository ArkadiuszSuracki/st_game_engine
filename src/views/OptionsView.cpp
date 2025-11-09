#include "views/OptionsView.h"

OptionsView::OptionsView(Font f) : font(f) {}

void OptionsView::Draw(bool fullscreen, int selected)
{
	ClearBackground((Color){20,20,30,255});

	DrawTextEx(font, "Options", { 40, 40 }, 48, 1, RAYWHITE);

	float x = 80.0f;
	float y = 140.0f;
	float fs = 32.0f;

	// opcja 1: fullscreen
	Color c1 = (selected == 0) ? YELLOW : RAYWHITE;
	const char *onOff = fullscreen ? "ON" : "OFF";
	std::string line1 = std::string("Fullscreen: ") + onOff;
	DrawTextEx(font, line1.c_str(), { x, y }, fs, 1, c1);

	// opcja 2: back
	Color c2 = (selected == 1) ? YELLOW : RAYWHITE;
	DrawTextEx(font, "Back", { x, y + fs + 16 }, fs, 1, c2);

	DrawTextEx(font, "UP/DOWN - select, ENTER - confirm, LEFT/RIGHT - change", { 40, 360 }, 20, 1, GRAY);
}
