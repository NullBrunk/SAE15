#include <Arduino.h>

// Classe permettant de déplacer la voiture dans un sens donné à une vitesse choisie
class Motors {
    
    public :
        Motors(uint8_t p_speed);

        void forward();
        void right();
        void left();

        void set_speed(int p_speed);
        void drive(float leftCoef, float rightCoef);

        void stop();
    
    private:
        uint8_t current_speed; 
};  
