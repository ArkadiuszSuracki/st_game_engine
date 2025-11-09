#include "controllers/GameController.h"
#include <cmath>

GameController::GameController(Font uiFont)
    : view(uiFont)
{
    camera = {0};
    camera.position = (Vector3){ 0.0f, 2.0f, 6.0f };
    camera.target   = (Vector3){ 0.0f, 2.0f, 5.0f };
    camera.up       = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy     = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    camYaw = 0.0f;
    camPitch = 0.0f;
    action = GameAction::None;

    DisableCursor(); // tryb FPS
}

void GameController::Update()
{
    float dt = GetFrameTime();

    // ESC -> wróć do menu
    if (IsKeyPressed(KEY_ESCAPE)) {
        action = GameAction::BackToMenu;
        EnableCursor(); // oddaj kursor
        return;
    }

    // mysz – obrót
    const float mouseSensitivity = 0.0035f;
    Vector2 md = GetMouseDelta();
    camYaw   += md.x * mouseSensitivity;
    camPitch -= md.y * mouseSensitivity;

    const float pitchLimit = PI/2.0f - 0.01f;
    if (camPitch >  pitchLimit) camPitch =  pitchLimit;
    if (camPitch < -pitchLimit) camPitch = -pitchLimit;

    // oblicz wektory
    Vector3 forward = {
        cosf(camPitch) * sinf(camYaw),
        sinf(camPitch),
        cosf(camPitch) * cosf(camYaw) * -1.0f
    };
    Vector3 right = {
        sinf(camYaw - PI/2.0f),
        0.0f,
        -cosf(camYaw - PI/2.0f)
    };

    const float moveSpeed = 6.0f;
    const float moveSpeedFast = 16.0f;
    float speed = IsKeyDown(KEY_LEFT_SHIFT) ? moveSpeedFast : moveSpeed;

    if (IsKeyDown(KEY_W)) {
        camera.position.x += forward.x * speed * dt;
        camera.position.y += forward.y * speed * dt;
        camera.position.z += forward.z * speed * dt;
    }
    if (IsKeyDown(KEY_S)) {
        camera.position.x -= forward.x * speed * dt;
        camera.position.y -= forward.y * speed * dt;
        camera.position.z -= forward.z * speed * dt;
    }
    if (IsKeyDown(KEY_D)) {
        camera.position.x += right.x * speed * dt;
        camera.position.z += right.z * speed * dt;
    }
    if (IsKeyDown(KEY_A)) {
        camera.position.x -= right.x * speed * dt;
        camera.position.z -= right.z * speed * dt;
    }
    if (IsKeyDown(KEY_SPACE)) camera.position.y += speed * dt;
    if (IsKeyDown(KEY_LEFT_CONTROL)) camera.position.y -= speed * dt;

    // ustaw target
    camera.target.x = camera.position.x + forward.x;
    camera.target.y = camera.position.y + forward.y;
    camera.target.z = camera.position.z + forward.z;
}

void GameController::Draw()
{
    ClearBackground(RAYWHITE);
    view.Draw3D(camera);
    view.DrawHUD(camera);
}

