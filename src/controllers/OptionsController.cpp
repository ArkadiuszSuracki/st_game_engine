#include "controllers/OptionsController.h"
#include "raylib.h"

OptionsController::OptionsController(Font uiFont)
	: view(uiFont)
{
	selected = 0;
	fullscreen = IsWindowFullscreen(); // start od stanu okna
	action = OptionsAction::None;
}

void OptionsController::Update()
{
	if (IsKeyPressed(KEY_UP))
	{
		selected--;
		if (selected < 0) selected = 1;
	}
	if (IsKeyPressed(KEY_DOWN))
	{
		selected++;
		if (selected > 1) selected = 0;
	}

	// zmiana wartości
	if (selected == 0)
	{
		if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_RIGHT))
		{
			fullscreen = !fullscreen;
			// natychmiast zastosuj
			if (fullscreen && !IsWindowFullscreen())
				ToggleFullscreen();
			else if (!fullscreen && IsWindowFullscreen())
				ToggleFullscreen();
		}
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		if (selected == 1)
		{
			action = OptionsAction::Back;
		}
	}
}

void OptionsController::Draw()
{
	view.Draw(fullscreen, selected);
}
