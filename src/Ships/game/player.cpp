#include <iostream>
#include "Ships/game/player.h";

void Player::PlayerMovement(){
    if(IsKeyDown(KEY_RIGHT)) this->Move(Vector2{(float)m_movementSpeed, 0});
    if(IsKeyDown(KEY_LEFT)) this->Move(Vector2{(float)-m_movementSpeed, 0});
    if(IsKeyDown(KEY_UP)) this->Move(Vector2{0, float()-m_movementSpeed});
    if(IsKeyDown(KEY_DOWN)) this->Move(Vector2{0, float(m_movementSpeed)});
}