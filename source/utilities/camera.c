#include "camera.h"

CAMERAFOLLOW createFollowCamera(PLAYER* player, float zoom) {
    CAMERAFOLLOW cameraFollow = { 0 };

    cameraFollow.targetPlayer = player;
    
    cameraFollow.camera.target = player -> position;
    cameraFollow.camera.zoom = zoom;

    return cameraFollow;
}

void updateFollowCamera(CAMERAFOLLOW* cameraFollow) {
    if (cameraFollow == NULL || cameraFollow -> targetPlayer == NULL) {
        return; 
    }

    cameraFollow -> camera.target = cameraFollow -> targetPlayer -> position;
}