#pragma once

#include "Ships/core/game_object.h"

class Entity : public GameObject{
    public: 
        Entity(std::string name, Vector2 pos, Vector2 size, int maxHP, std::string texturePath = "assets/textures/noTexture.png")
            : GameObject(name, pos, size, texturePath),  
            m_maxHP(maxHP)                           
        {
            m_isAlive = true;
        }
        virtual ~Entity() {}
        
        void DealDamage(int dmg);
        
        bool IsAlive(){
            return m_isAlive;
        }

    private:
        int m_maxHP;
        bool m_isAlive;

        void DeathCheck();
        void Death();
};