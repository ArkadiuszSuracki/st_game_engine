#include "controllers/MenuController.h"
#include "raylib.h"

MenuController::MenuController(Font uiFont)
	: view(uiFont)
{
	items = { "Play Game", "Options", "Exit" };
	selected = 0;
	action = MenuAction::None;
}

void MenuController::Update()
{
	if (IsKeyPressed(KEY_UP))
	{
		selected--;
		if (selected < 0) selected = (int)items.size() - 1;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		selected++;
		if (selected >= (int)items.size()) selected = 0;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		if (selected == 0) action = MenuAction::Play;
		else if (selected == 1) action = MenuAction::Options;
		else if (selected == 2) action = MenuAction::Exit;
	}
}

void MenuController::Draw()
{
	ClearBackground((Color){30,30,30,255});
	DrawText("st_game_engine", 40, 40, 24, RAYWHITE);
	view.Draw(items, selected);
}
