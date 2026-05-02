#pragma once

#include "Ships/game/entity.h"
#include "Ships/core/timer.h"

class Player : public Entity{
    public:
        Player(std::string name, Vector2 pos, Vector2 size, int maxHP, std::string texturePath = "assets/textures/noTexture.png")
            : Entity(name, pos, size, maxHP, texturePath)
        {
            
        }
        virtual ~Player() {}

        void PlayerMovement(float deltaTime);

    private:
        int m_movementSpeed = 5;
        float m_shotsPerSecond = 4;
        Timer m_shootingTimer = Timer(10);
};