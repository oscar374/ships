#pragma once

#include "ships/core/game_object.h"

class Projectile : public GameObject {
    public: 
        Projectile(std::string name, Vector2 pos, Vector2 size, Vector2 movementVector, std::string texturePath = "assets/textures/noTexture.png")
        : GameObject(name, pos, size, texturePath),
        m_movementVector(movementVector)
        {

        }
        virtual ~Projectile() {}

        Vector2 GetMovementVector(){
            return m_movementVector;
        }

    private:
        Vector2 m_movementVector;
        
};