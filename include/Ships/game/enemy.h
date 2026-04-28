#pragma once

#include "Ships/game/entity.h"

class Enemy : public Entity {
public:
    Enemy(std::string name, Vector2 pos, Vector2 size, int maxHP,
          int damage, float attacksPerSecond, int projectileCount,
          std::string texturePath = "assets/textures/noTexture.png")
        : Entity(name, pos, size, maxHP, texturePath),
          m_damage(damage),
          m_attacksPerSecond(attacksPerSecond),
          m_projectileCount(projectileCount)
    {
    }
    virtual ~Enemy() {}


    int GetDamage() const {
        return m_damage;
    }

    float GetAttacksPerSecond() const {
        return m_attacksPerSecond;
    }

    void Shoot();

private:
    int m_damage;
    float m_attacksPerSecond;
    int m_projectileCount;
};