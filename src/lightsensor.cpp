#include "../include/lightsensor.hpp"
#include <Arduino.h>

/**
    Constructeur de la classe LightSensor

    @param int p_port   Le port du lightsensor 
                            GAUCHE: A2
                            CENTRE: A1
                            DROITE: A0
*/
LightSensor::LightSensor(int p_port) {
    port = p_port; 
}


/**
    Méthode de classe permettant de savoir si le capteur se trouve sur du noir ou pas.

    @return true    Le capteur capte du noir
    @return false   Le capteur ne capte pas de noir
*/
bool LightSensor::detect(){
    int state = analogRead(port);
    Serial.println(state);
    return state >= 650;
} 
