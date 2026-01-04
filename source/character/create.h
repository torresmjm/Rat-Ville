#include "raylib.h"

typedef struct PortraitTexture {
    int faceShape;
    Texture2D portrait;

} PORTRAITTEXTURE;

void initializeCreator(PORTRAITTEXTURE *portraitTexture);
void updateCreator(PORTRAITTEXTURE *portraitTexture);
void drawCreator(PORTRAITTEXTURE *portraitTexture);
void unloadCreator(PORTRAITTEXTURE *portraitTexture);