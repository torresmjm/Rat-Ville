#include "player.h"

PLAYER* createPlayer(Vector2 position) {
    PLAYER* newPlayer = (PLAYER*)malloc(sizeof(PLAYER));
    newPlayer->position = position;
    newPlayer->speed = 200.0f;
    newPlayer->maxSpeed = 400.0f;

    newPlayer->playerTexture.body = LoadTexture("assets/playerbase_body.png");
    newPlayer->playerTexture.arms = LoadTexture("assets/playerbase_arms.png");
    newPlayer->playerTexture.legs = LoadTexture("assets/playerbase_legs.png");
    
    return newPlayer;
}

void RenderPlayerBodyTextures(PLAYER* player) {
    TEXTURE tempBody = {player -> playerTexture.body, player -> position};
    TEXTURE tempArms = {player -> playerTexture.arms, player -> position};
    TEXTURE tempLegs = {player -> playerTexture.legs, player -> position};
    
    RenderCustomTexture(&tempBody);
    RenderCustomTexture(&tempArms);
    RenderCustomTexture(&tempLegs);
}

void updatePlayer(PLAYER* player, float deltaTime) {
    if (IsKeyDown(KEY_W)) player -> position.y -= player -> speed * deltaTime;
    if (IsKeyDown(KEY_S)) player -> position.y += player -> speed * deltaTime;
    if (IsKeyDown(KEY_A)) player -> position.x -= player -> speed * deltaTime;
    if (IsKeyDown(KEY_D)) player -> position.x += player -> speed * deltaTime;
}

void unloadPlayer(PLAYER* player) {
    free(player);
}