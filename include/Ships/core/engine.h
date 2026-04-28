#pragma once

#include "memory.h"
#include "vector"
#include "Ships/game/enemyController.h"

#include <raylib.h>

#include "scene.h"

class Engine{
    public: 
        Engine();
    private:
        void Render();
        void Frame();
        void Start();

        int m_windowWidth = 500;
        int m_windowHeight = 800;
        
        std::unique_ptr<Scene> m_currentScene;
        std::unique_ptr<EnemyController> m_enemyController;
};