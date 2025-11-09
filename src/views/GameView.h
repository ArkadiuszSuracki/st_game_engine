#ifndef VIEWS_GAME_VIEW_H
#define VIEWS_GAME_VIEW_H

#include "raylib.h"

class GameView
{
public:
    GameView(Font f);

    void Draw3D(const Camera3D &camera);
    void DrawHUD(const Camera3D &camera);

private:
    Font font;
};

#endif

