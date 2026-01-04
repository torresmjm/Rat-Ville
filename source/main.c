#include "raylib.h"
#include "game/player.h"


int main() {

    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(1920, 1080, "Conbini");

    SetTargetFPS(60);

    PLAYER* player = createPlayer((Vector2){100, 100});

    while (!WindowShouldClose()) {
        updatePlayer(player, GetFrameTime());
        BeginDrawing();

        ClearBackground(RAYWHITE);
        RenderPlayerBodyTextures(player);
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}