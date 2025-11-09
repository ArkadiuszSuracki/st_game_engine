#include "views/GameView.h"
#include <cstdio>

GameView::GameView(Font f) : font(f) {}

void GameView::Draw3D(const Camera3D &camera)
{
    BeginMode3D(camera);
        DrawGrid(30, 1.0f);
        DrawCube((Vector3){ 0, 1, 0 }, 1.0f, 2.0f, 1.0f, RED);
        DrawCube((Vector3){ 3, 0.5f, 3 }, 1.0f, 1.0f, 1.0f, BLUE);
        DrawCube((Vector3){ -3, 0.5f, -2 }, 1.0f, 1.0f, 1.0f, GREEN);
    EndMode3D();
}

void GameView::DrawHUD(const Camera3D &camera)
{
    // tło
    DrawRectangle(10, 10, 360, 120, Fade(BLACK, 0.4f));
    DrawRectangleLines(10, 10, 360, 120, Fade(WHITE, 0.4f));

    float fontSize = 22.0f;
    float spacing = 1.0f;
    Vector2 pos = { 20.0f, 20.0f };
    char line[128];

    snprintf(line, sizeof(line), "Pos: (%.2f, %.2f, %.2f)",
             camera.position.x, camera.position.y, camera.position.z);
    DrawTextEx(font, line, pos, fontSize, spacing, WHITE);
    pos.y += fontSize + 2;

    snprintf(line, sizeof(line), "FPS: %d", GetFPS());
    DrawTextEx(font, line, pos, fontSize, spacing, WHITE);
    pos.y += fontSize + 2;

    DrawTextEx(font, "ESC - back to menu", pos, fontSize - 2, spacing, YELLOW);
}

