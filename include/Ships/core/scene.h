#pragma once

#include <memory>
#include <vector>

#include "game_object.h"
#include "Ships/game/enemy.h"
#include "Ships/game/player.h"
#include "Ships/game/projectile.h"

class Scene{
    public:
        void AddGameObject(std::shared_ptr<GameObject> obj);

        const std::vector<std::shared_ptr<GameObject>>& GetGameObjects() const {
            return m_gameObjects;
        }

        const std::vector<std::shared_ptr<Enemy>>& GetEnemies() const {
            return m_enemies;
        }

        const std::vector<std::shared_ptr<Projectile>>& GetProjectiles() const {
            return m_projectiles;
        }

        const std::shared_ptr<Player> GetPlayer() const {
            return m_player;
        }

    private:
        std::vector<std::shared_ptr<GameObject>> m_gameObjects;
        std::vector<std::shared_ptr<Enemy>> m_enemies;
        std::vector<std::shared_ptr<Projectile>> m_projectiles;

        std::shared_ptr<Player> m_player;
};