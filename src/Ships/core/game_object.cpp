#include "Ships/core/game_object.h"

GameObject::GameObject(std::string name, Vector2 pos, Vector2 size, std::string texturePath){
    m_name = name;
    m_position = pos;
    m_size = size;
    m_texturePath = texturePath;

    LoadTexture();
};

void GameObject::LoadTexture(){
    const char * charTexturePath = m_texturePath.c_str();
    m_image = LoadImage(charTexturePath);
    m_texture = LoadTextureFromImage(m_image);
    UnloadImage(m_image);

    m_image = LoadImageFromTexture(m_texture);
    UnloadTexture(m_texture);

    m_texture = LoadTextureFromImage(m_image);
    UnloadImage(m_image);
}

void GameObject::Move(Vector2 offset){
    Vector2 newPosition = Vector2{m_position.x + offset.x, m_position.y + offset.y};
    m_position = newPosition;
}