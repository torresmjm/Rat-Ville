#include "raylib.h"

typedef struct TextureToLoad {
    Texture2D texture;
    Vector2 position;
} TEXTURE;


TEXTURE LoadTextureFromFile(const char* filePath, Vector2 position);

void RenderCustomTexture(TEXTURE* textureToRender);

void UnloadTextureResource(TEXTURE* textureToUnload);