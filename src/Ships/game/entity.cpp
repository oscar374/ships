#include "Ships/game/entity.h"

void Entity::DealDamage(int dmg){
    m_maxHP -= dmg;
    DeathCheck();
}

void Entity::DeathCheck(){
    if(m_maxHP <= 0) Death();
}

void Entity::Death(){
    m_isAlive = false;
}

