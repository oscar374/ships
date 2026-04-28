// ################## MAIN ENGINE / GAME CLASS ##################
// Game made by Oskar Pach | github: oscar374

#include "Ships/core/engine.h"
#include <iostream>

Engine::Engine(){
    Start();
    while(!WindowShouldClose()) Frame();
    CloseWindow();
}

void Engine::Start(){
    InitWindow(m_windowWidth, m_windowHeight, "Ships");
    SetTargetFPS(60);

    m_currentScene = std::make_unique<Scene>();
    m_enemyController = std::make_unique<EnemyController>(m_windowWidth, m_windowHeight);

    auto enemy = std::make_shared<Enemy>("debil", Vector2{100, 100}, Vector2{60, 60}, 50, 10, 1, 1, "assets/textures/ships/enemies/enemy1.png");
    auto enemy2 = std::make_shared<Enemy>("debil", Vector2{100, 150}, Vector2{80, 80}, 50, 10, 1, 1, "assets/textures/ships/enemies/enemy1.png");
    auto enemy3 = std::make_shared<Enemy>("debil", Vector2{100, 200}, Vector2{60, 60}, 50, 10, 1, 1, "assets/textures/ships/enemies/enemy1.png");

    auto player1 = std::make_shared<Player>("playa", Vector2{100, 200}, Vector2{60, 60}, 50, "assets/textures/ships/ship1.png");

    m_currentScene->AddGameObject(enemy);
    m_currentScene->AddGameObject(enemy2);
    m_currentScene->AddGameObject(enemy3);
    m_currentScene->AddGameObject(player1);

    m_enemyController->SetEnemies(m_currentScene->GetEnemies());
    m_enemyController->AutoSetEnemiesPosition();
}

void Engine::Frame(){
    BeginDrawing();
    ClearBackground(BLACK);
        
    m_enemyController->MoveEnemies();
    m_currentScene->GetPlayer()->PlayerMovement();

    Render();

    EndDrawing();
}

void Engine::Render(){
    for(const auto& obj : m_currentScene->GetGameObjects()){   
        Texture2D txt = obj->GetTexture();
        Rectangle dest = {obj->GetPosition().x, obj->GetPosition().y, obj->GetSize().x, obj->GetSize().y};

        DrawTexturePro(
            txt,
            Rectangle{0, 0, (float)txt.width, (float)txt.height},
            dest,
            Vector2{0, 0},
            0.0f,
            WHITE
        );

        DrawText("HP: 100", 10, m_windowHeight - 40, 30, WHITE);
    }
}