#include "Ships/core/scene.h"

void Scene::AddGameObject(std::shared_ptr<GameObject> obj) {
    m_gameObjects.push_back(obj);

    //sorting gameobjects based on their type
    if(auto enemy = std::dynamic_pointer_cast<Enemy>(obj)){
        m_enemies.push_back(enemy);
    }
    if(auto projectile = std::dynamic_pointer_cast<Projectile>(obj)){
        m_projectiles.push_back(projectile);
    }
    if(auto player = std::dynamic_pointer_cast<Player>(obj)){
        m_player = player;
    }
};

