#pragma once

#include "memory"
#include "vector"

#include "ships/game/projectile.h"

class ProjectileController {
    public:
        void MoveProjectiles(const std::vector<std::shared_ptr<Projectile>>& projectiles);
    private:
};