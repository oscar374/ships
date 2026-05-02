#pragma once

#include "memory.h"
#include "vector"
#include "Ships/game/enemyController.h"
#include "Ships/game/projectileController.h"

#include <raylib.h>

#include "scene.h"

class Engine{
    public: 
        Engine();
        Scene* GetScene(){
            return m_currentScene.get();
        }
        Vector2 GetWindowProportions(){
            return Vector2{(float)m_windowWidth, (float)m_windowHeight};
        }
    private:
        void Render();
        void Frame();
        void Start();

        int m_windowWidth = 500;
        int m_windowHeight = 800;

        float m_gameSpeed = 80;
        
        std::unique_ptr<Scene> m_currentScene;
        std::unique_ptr<EnemyController> m_enemyController;
        std::unique_ptr<ProjectileController> m_projectileController;
};