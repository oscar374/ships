#include "Ships/game/player.h"

#include <iostream>
#include "Ships/core/service_locator.h"

#include "Ships/game/projectile.h"

void Player::PlayerMovement(float deltaTime){
    if(IsKeyDown(KEY_RIGHT)) this->Move(Vector2{(float)m_movementSpeed * deltaTime, 0});
    if(IsKeyDown(KEY_LEFT)) this->Move(Vector2{(float)-m_movementSpeed * deltaTime, 0});
    if(IsKeyDown(KEY_UP)) this->Move(Vector2{0, float()-m_movementSpeed * deltaTime});
    if(IsKeyDown(KEY_DOWN)) this->Move(Vector2{0, float(m_movementSpeed * deltaTime)});


    if(m_shootingTimer.Work(deltaTime)){
        Scene* scene = ServiceLocator::getEngine()->GetScene();

        auto projectile = std::make_shared<Projectile>(
            "proj",
            Vector2{scene->GetPlayer()->GetPosition().x + (scene->GetPlayer()->GetSize().x / 2), scene->GetPlayer()->GetPosition().y},
            Vector2{4, 32},
            Vector2{0, -10},
            "assets/textures/projectiles/projectile.png"
        ); 
        
        scene->AddGameObject(projectile);
    }
}