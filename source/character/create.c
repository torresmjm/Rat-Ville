#include "create.h"

static Texture2D LoadFaceTexture(int shape) {
    char path[128];
    snprintf(path, sizeof(path), "assets/portrait_male_shape_%d.png", shape);
    return LoadTexture(path);
}

void initializeCreator(PORTRAITTEXTURE *portraitTexture) {
    portraitTexture -> faceShape = 1;
    portraitTexture -> portrait = LoadFaceTexture(portraitTexture -> faceShape);
}

void updateCreator(PORTRAITTEXTURE *portraitTexture) {
    if (IsKeyPressed(KEY_RIGHT)) {
        portraitTexture -> faceShape++;
        if (portraitTexture -> faceShape > 5) {
            portraitTexture -> faceShape = 1;
        }
        UnloadTexture(portraitTexture -> portrait);
        portraitTexture -> portrait = LoadFaceTexture(portraitTexture -> faceShape);
    }
    if (IsKeyPressed(KEY_LEFT)) {
        portraitTexture -> faceShape--;
        if (portraitTexture -> faceShape < 1) {
            portraitTexture -> faceShape = 5;
        }
        UnloadTexture(portraitTexture -> portrait);
        portraitTexture -> portrait = LoadFaceTexture(portraitTexture -> faceShape);
    }
}

void drawCreator(PORTRAITTEXTURE *portraitTexture) {
    DrawTextureV(portraitTexture -> portrait, (Vector2){200, 100}, WHITE);
    DrawText("Use LEFT and RIGHT arrows to change face shape", 50, 300, 20, BLACK);
}

void unloadCreator(PORTRAITTEXTURE *portraitTexture) {
    UnloadTexture(portraitTexture -> portrait);
}