#include "screenmanager.h"

static PLAYER* player = NULL;
static CAMERAFOLLOW gameCamera;
static PORTRAITTEXTURE creator;
static TEXTURE testTexture;

void InitializeScreenManager(){
    player = createPlayer((Vector2){100, 100});
    gameCamera = createFollowCamera(player, 4.0f);
    creator.faceShape = 0;
    initializeCreator(&creator);
    testTexture = LoadTextureFromFile("assets/test.png", (Vector2){0,0});
}

void ChangeScreen(SCREEN *currentScreen) {
    switch (*currentScreen) {
        case INTRO:{
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                *currentScreen = TITLE;
            }
        } break;
        case TITLE:{
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                *currentScreen = GAME;
            }   
            updateCreator(&creator);
        } break;
        case GAME:{
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                *currentScreen = INTRO;
            }
            if (player != NULL) {  
                updatePlayer(player, GetFrameTime());
                updateFollowCamera(&gameCamera);
            }
        } break;
        default: break;
    }
}

void RenderScreen(SCREEN *currentScreen){
    switch (*currentScreen) {
        case INTRO:{
            DrawText("INTRO SCREEN", 120, 20, 80, LIGHTGRAY);
            
        } break;
        case TITLE:{
            DrawText("TITLE SCREEN", 120, 20, 80, LIGHTGRAY);
            DrawTextureEx(testTexture.texture, testTexture.position,0, 2, WHITE);
            drawCreator(&creator);
        } break;
        case GAME:{
            DrawText("GAME SCREEN", 120, 20, 80, LIGHTGRAY);
            if (player != NULL) {
                BeginMode2D(gameCamera.camera);  
                int gridSize = 100;
                for (int i = -1000; i < 2000; i += gridSize) {
                    DrawLine(i, -1000, i, 2000, DARKGRAY); // Vertical lines
                    DrawLine(-1000, i, 2000, i, DARKGRAY); // Horizontal lines
                }
                RenderPlayerBodyTextures(player);
                EndMode2D();
            }
        } break;
        default: break;
    }
}

void UnloadScreenManager() {
    if (player != NULL) {
        unloadPlayer(player);  
        player = NULL;
    }
}