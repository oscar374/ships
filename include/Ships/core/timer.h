class Timer{
    public:
        Timer(float delay){
            m_delay = delay;
        }

        bool Work(float deltaTime);

        float time;    
    private:
        float m_delay = 1;
};