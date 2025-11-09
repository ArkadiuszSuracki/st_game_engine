#include "core/DebugOverlay.h"

DebugOverlay::DebugOverlay()
{
	visible = false;
	font = GetFontDefault();
}

void DebugOverlay::SetFont(Font f)
{
	font = f;
}

void DebugOverlay::AddLine(const std::string &line)
{
	lines.push_back(line);
	if (lines.size() > 20) {
		lines.erase(lines.begin());
	}
}

void DebugOverlay::Clear()
{
	lines.clear();
}

void DebugOverlay::Toggle()
{
	visible = !visible;
}

void DebugOverlay::Draw()
{
	if (!visible) return;

	int sw = GetScreenWidth();

	DrawRectangle(5, 5, sw - 10, 20 + (int)lines.size() * 20, Fade(BLACK, 0.6f));
	DrawRectangleLines(5, 5, sw - 10, 20 + (int)lines.size() * 20, Fade(WHITE, 0.6f));

	Vector2 pos = { 10.0f, 10.0f };
	for (const auto &l : lines)
	{
		DrawTextEx(font, l.c_str(), pos, 18, 1, RAYWHITE);
		pos.y += 20;
	}
}

