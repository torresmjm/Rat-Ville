#include "raylib.h"
#include "screen/screenmanager.h"

int main() {

    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(1920, 1080, "Conbini");

    SetTargetFPS(60);

    SCREEN currentScreen = INTRO;
    InitializeScreenManager();

    while (!WindowShouldClose()) {
        ChangeScreen(&currentScreen);
        BeginDrawing();

        ClearBackground(RAYWHITE);
        RenderScreen(&currentScreen);
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}