#include "Ships/core/engine.h"

class ServiceLocator{
    public:
        static void setEngine(Engine* engine) {
            m_engine = engine;
        }
        static Engine* getEngine(){
            return m_engine;
        }
    private:
        static Engine* m_engine;
};