#include "raylib.h"
#include "utilities/texture.h"

typedef struct PlayerBodyTexture {
    Texture2D body;
    Texture2D arms;
    Texture2D legs;
} PLAYERBODYTEXTURE;

typedef struct {
    PLAYERBODYTEXTURE playerTexture;
    Vector2 position;
    float speed;
    float maxSpeed;
} PLAYER;

PLAYER* createPlayer(Vector2 position);
void RenderPlayerBodyTextures(PLAYER* player);
void updatePlayer(PLAYER* player, float deltaTime);
void unloadPlayer(PLAYER* player);


