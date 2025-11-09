#ifndef CORE_RESOURCE_MANAGER_H
#define CORE_RESOURCE_MANAGER_H

#include "raylib.h"

class ResourceManager
{
public:
	void LoadFonts();
	Font GetMainFont() const { return mainFont; }

private:
	Font mainFont;
};

#endif

