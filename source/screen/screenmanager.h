#include "raylib.h"
#include <stdio.h>
#include "utilities/camera.h"
#include "character/create.h"

typedef enum ScreenToLoad {
    INTRO,
    TITLE,
    GAME,
} SCREEN;

void InitializeScreenManager();

void ChangeScreen(SCREEN *currentScreen);

void RenderScreen(SCREEN *currentScreen);

void UnloadScreenManager();