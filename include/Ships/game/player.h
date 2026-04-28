#pragma once

#include "Ships/game/entity.h";

class Player : public Entity{
    public:
        Player(std::string name, Vector2 pos, Vector2 size, int maxHP, std::string texturePath = "assets/textures/noTexture.png")
            : Entity(name, pos, size, maxHP, texturePath)
        {
            
        }
        virtual ~Player() {}

        void PlayerMovement();

    private:
        int m_movementSpeed = 5;
};