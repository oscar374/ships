#include "Ships/core/timer.h"

bool Timer::Work(float deltaTime){
    time += deltaTime;
    if(time >= m_delay){
        time = 0;
        return true;
    } else {
        return false;
    }
}