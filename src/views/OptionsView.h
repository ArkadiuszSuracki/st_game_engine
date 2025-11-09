#ifndef VIEWS_OPTIONS_VIEW_H
#define VIEWS_OPTIONS_VIEW_H

#include "raylib.h"
#include <string>

class OptionsView
{
public:
	OptionsView(Font f);
	void Draw(bool fullscreen, int selected);

private:
	Font font;
};

#endif

