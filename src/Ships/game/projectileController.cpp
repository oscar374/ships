#include "ships/game/projectileController.h"

#include <iostream>

void ProjectileController::MoveProjectiles(const std::vector<std::shared_ptr<Projectile>>& projectiles){
    for (auto& projectile : projectiles) {
        projectile->Move(projectile->GetMovementVector());
    }
}