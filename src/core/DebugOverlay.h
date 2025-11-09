#ifndef CORE_DEBUG_OVERLAY_H
#define CORE_DEBUG_OVERLAY_H

#include "raylib.h"
#include <string>
#include <vector>

class DebugOverlay {
public:
	DebugOverlay();

	void SetFont(Font f);
	void AddLine(const std::string &line);
	void Clear();
	void Toggle();
	void Draw();

private:
	bool visible;
	Font font;
	std::vector<std::string> lines;
};

#endif

