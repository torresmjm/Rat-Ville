#include <raylib.h>
#include "game/player.h" 
#include <stdio.h>

typedef struct CameraFollow {
    Camera2D camera;
    PLAYER* targetPlayer;
} CAMERAFOLLOW;

CAMERAFOLLOW createFollowCamera(PLAYER* player, float zoom);

void updateFollowCamera(CAMERAFOLLOW* cameraFollow);