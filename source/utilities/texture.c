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

void RenderBreathingTexture(TEXTURE* textureToRender, float scaleFactor) {
    static float timer = 0.0f;

    timer += GetFrameTime(); 

    float vibrationAmount = 0.5f; 
    float period = 2.0f;
    float offsetY = vibrationAmount * sinf((timer / period) * 2 * PI);

    DrawTexture(textureToRender -> texture, textureToRender -> position.x, textureToRender -> position.y + offsetY, WHITE);
}

void UnloadTextureResource(TEXTURE* textureToUnload) {
    UnloadTexture(textureToUnload -> texture);
}