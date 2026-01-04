#include "texture.h"

TEXTURE LoadTextureFromFile(const char* filePath, Vector2 position) {
    TEXTURE newTexture;
    newTexture.texture = LoadTexture(filePath);
    newTexture.position = position;
    
    return newTexture;
}

void RenderCustomTexture(TEXTURE* textureToRender) {
    DrawTextureV(textureToRender -> texture, textureToRender -> position, WHITE);
}

void UnloadTextureResource(TEXTURE* textureToUnload) {
    UnloadTexture(textureToUnload -> texture);
}