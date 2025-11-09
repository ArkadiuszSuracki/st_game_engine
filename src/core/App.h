#ifndef CORE_APP_H
#define CORE_APP_H

#include "core/Config.h"
#include "core/ResourceManager.h"
#include "core/DebugOverlay.h"
#include "controllers/BaseController.h"

enum class Screen {
	Menu,
	Options,
	Game   // na później
};

class App
{
public:
	App();
	~App();

	void Run();

private:
	Config cfg;
	ResourceManager resources;
	DebugOverlay debug;

	BaseController *controller;
	Screen currentScreen;

	void SwitchTo(Screen s);
};

#endif
