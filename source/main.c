#include "raylib.h"

int main() {

    SetConfigFlags(FLAG_BORDERLESS_WINDOWED_MODE);
    InitWindow(1920, 1080, "Rat Ville");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Welcome to Rat Ville!", 650, 500, 50, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}