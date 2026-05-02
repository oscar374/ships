#pragma once

#include "memory"
#include "vector"
#include "enemy.h"

class EnemyController{
    public:
        EnemyController(int windowWidth, int windowHeight){
            m_windowWidth = windowWidth;
            m_windowHeight = windowHeight;
        }
        void SetEnemies(std::vector<std::shared_ptr<Enemy>> enemies){
            m_enemies = enemies;
        }
        void MoveEnemies(float deltaTime);
        void AutoSetEnemiesPosition();
    private:
        void CalculateTotalEnemiesWidth();
        void CheckMovement();
        void DirectionChangeCheck();

        int m_totalEnemiesWidth;

        std::vector<std::shared_ptr<Enemy>> m_enemies;

        int m_windowWidth;    
        int m_windowHeight;     

        bool m_enemiesDirection = true;  // false is left   |   true is right
        int m_enemiesMargin = 10;
        int m_enemiesSpeed = 2;
};