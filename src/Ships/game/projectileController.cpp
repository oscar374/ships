#include "ships/game/projectileController.h"

#include <iostream>

void ProjectileController::MoveProjectiles(const std::vector<std::shared_ptr<Projectile>>& projectiles, float deltaTime){
    for (auto& projectile : projectiles) {
        Vector2 finalVector = Vector2{
            projectile->GetMovementVector().x * deltaTime,
            projectile->GetMovementVector().y * deltaTime
        };
        
        projectile->Move(finalVector);
    }
}