#include "ships/game/enemyController.h"

void EnemyController::MoveEnemies(){
    int output;

    if(m_enemiesDirection) output = m_enemiesSpeed;
    else output = -m_enemiesSpeed;

    for(const auto& enemy : m_enemies){
        enemy->Move(Vector2{(float)output, 0});
    }
    DirectionChangeCheck();
}

void EnemyController::AutoSetEnemiesPosition(){
    int xPos = 0;
    int yPos = 50;
    
    for(const auto& enemy : m_enemies){
        enemy->SetPosition(Vector2{(float)xPos, (float)yPos});
        xPos += enemy->GetSize().x + m_enemiesMargin;
    }   

    CalculateTotalEnemiesWidth();
}

void EnemyController::CalculateTotalEnemiesWidth(){
    int total = 0;
    for(const auto& enemy : m_enemies)
        total += enemy->GetSize().x;
    m_totalEnemiesWidth = total + m_enemiesMargin * 2;
}

void EnemyController::DirectionChangeCheck(){
    int firstEnemyXPosition = m_enemies[0]->GetPosition().x;

    if(m_enemiesDirection && m_totalEnemiesWidth + firstEnemyXPosition > m_windowWidth)
        m_enemiesDirection = false; // start going left
    if(firstEnemyXPosition < 0)
        m_enemiesDirection = true; // start goinf right
}