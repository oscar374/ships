#pragma once
#include "string"

#include "raylib.h"

class GameObject{
    public:
        GameObject(std::string name, Vector2 pos, Vector2 size, std::string texturePath = "assets/textures/noTexture.png");
        virtual ~GameObject() {}
        
        void Move(Vector2 offset);

        std::string GetName(){
            return m_name;
        }

        Vector2 GetPosition(){
            return m_position;
        }

        void SetPosition(Vector2 pos){
            m_position = pos;
        }

        Vector2 GetSize(){
            return m_size;
        }

        void SetSize(Vector2 size){
            m_size = size;
        }
        
        void SetTexturePath(std::string newPath){
            m_texturePath = newPath;
        }

        Texture2D GetTexture(){
            return m_texture;
        }
    private:
        void LoadTexture();

        std::string m_name;
        Vector2 m_position;
        Vector2 m_size; 
        std::string m_texturePath;

        Image m_image;
        Texture2D m_texture;
};