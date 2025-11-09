#include "core/App.h"
#include "controllers/MenuController.h"
#include "controllers/OptionsController.h"
#include "controllers/GameController.h"
#include "raylib.h"
#include <string>

static const char* ScreenToString(Screen s)
{
	switch (s)
	{
		case Screen::Menu:    return "Menu";
		case Screen::Options: return "Options";
		case Screen::Game:    return "Game";
	}
	return "Unknown";
}

App::App()
{
	cfg = LoadConfig("config.ini");

	debug.AddLine(DumpConfig(cfg));

	InitWindow(cfg.windowWidth, cfg.windowHeight, cfg.windowTitle.c_str());
	SetExitKey(KEY_NULL);
	SetTargetFPS(60);

	resources.LoadFonts();

	// ustaw font dla debug overlay
	debug.SetFont(resources.GetMainFont());
	debug.AddLine("App started");

	currentScreen = Screen::Menu;
	controller = new MenuController(resources.GetMainFont());
}

App::~App()
{
	delete controller;
	CloseWindow();
}

void App::SwitchTo(Screen s)
{
	// usuń stary kontroler
	if (controller) {
		delete controller;
		controller = nullptr;
	}
	currentScreen = s;

	debug.AddLine(std::string("currentScreen: ") + ScreenToString(s));

	if (s == Screen::Menu)
	{
		controller = new MenuController(resources.GetMainFont());
	}
	else if (s == Screen::Options)
	{
		controller = new OptionsController(resources.GetMainFont());
	}
	else if (s == Screen::Game)
	{
		controller = new GameController(resources.GetMainFont());
	}

}

void App::Run()
{
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_GRAVE)) {
			debug.Toggle();
		}

		controller->Update();

		// tu reagujemy na akcje ekranów
		if (currentScreen == Screen::Menu)
		{
			auto *mc = dynamic_cast<MenuController*>(controller);
			if (mc)
			{
				MenuAction act = mc->GetAction();
				if (act == MenuAction::Play)
				{
					mc->ClearAction();
					SwitchTo(Screen::Game);
				}
				else if (act == MenuAction::Options)
				{
					mc->ClearAction();
					SwitchTo(Screen::Options);
				}
				else if (act == MenuAction::Exit)
				{
					break;
				}
			}
		}
		else if (currentScreen == Screen::Options)
		{
			auto *oc = dynamic_cast<OptionsController*>(controller);
			if (oc)
			{
				OptionsAction a = oc->GetAction();
				if (a == OptionsAction::Back)
				{
					oc->ClearAction();
					SwitchTo(Screen::Menu);
				}
			}
		}
		else if (currentScreen == Screen::Game)
		{
			auto *gc = dynamic_cast<GameController*>(controller);
			if (gc)
			{
				if (gc->GetAction() == GameAction::BackToMenu)
				{
					gc->ClearAction();
					SwitchTo(Screen::Menu);
				}
			}
		}


		BeginDrawing();
			controller->Draw();
			debug.Draw();
		EndDrawing();
	}
}
