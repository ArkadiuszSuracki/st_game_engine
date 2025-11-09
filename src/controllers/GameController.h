#ifndef CONTROLLERS_GAME_CONTROLLER_H
#define CONTROLLERS_GAME_CONTROLLER_H

#include "controllers/BaseController.h"
#include "views/GameView.h"
#include "raylib.h"

enum class GameAction {
    None,
    BackToMenu
};

class GameController : public BaseController
{
public:
    GameController(Font uiFont);

    void Update() override;
    void Draw() override;

    GameAction GetAction() const { return action; }
    void ClearAction() { action = GameAction::None; }

private:
    GameView view;
    Camera3D camera;
    float camYaw;
    float camPitch;
    GameAction action;
};

#endif

