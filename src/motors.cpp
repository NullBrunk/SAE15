#include "../include/motors.hpp"
#include <Arduino.h>

#define GLOBAL_MOTOR 3

// analogWrite de la vitesse
#define RIGHT_WHEELS_SPEED 5
#define LEFT_WHEELS_SPEED 6

// digitalWrite HIGH = vers l'avant, digitalWrite LOW = vers l'arrière 
#define RIGHT_WHEELS_DIRECTION 7
#define LEFT_WHEELS_DIRECTION 8


/**
    Constructeur de la classe Motors

    @param uint8_t p_speed La vitesse initiale de notre voiture comprise entre 0 et 255
*/
Motors::Motors(uint8_t p_speed) {
    current_speed = p_speed;

    pinMode(GLOBAL_MOTOR, OUTPUT);
    
    pinMode(RIGHT_WHEELS_DIRECTION, OUTPUT);
    pinMode(LEFT_WHEELS_DIRECTION, OUTPUT);

    pinMode(RIGHT_WHEELS_SPEED, OUTPUT);
    pinMode(LEFT_WHEELS_SPEED, OUTPUT);
}


/**
    Méthode permettant de faire avancer la voiture en ligne droite

    Sens des roues
        DROITES:        Avant
        GAUCHES:        Avant
*/
void Motors::forward() {
    digitalWrite(GLOBAL_MOTOR, HIGH);

    digitalWrite(RIGHT_WHEELS_DIRECTION, HIGH);
    analogWrite(RIGHT_WHEELS_SPEED, current_speed);


    digitalWrite(LEFT_WHEELS_DIRECTION, HIGH);
    analogWrite(LEFT_WHEELS_SPEED, current_speed);
}


/**
    Méthode permettant de faire tourner la voiture vers la droite

    Sens des roues
        DROITES:        Arrière
        GAUCHES:        Avant
*/
void Motors::right() {
    digitalWrite(GLOBAL_MOTOR, HIGH);

    digitalWrite(RIGHT_WHEELS_DIRECTION, LOW);
    analogWrite(RIGHT_WHEELS_SPEED, current_speed);

    digitalWrite(LEFT_WHEELS_DIRECTION, HIGH);
    analogWrite(LEFT_WHEELS_SPEED, current_speed);
}


/**
    Méthode permettant de faire tourner la voiture vers la gauche

    Sens des roues
        DROITES:        Avant
        GAUCHES:        Arrière
*/
void Motors::left() {
    digitalWrite(GLOBAL_MOTOR, HIGH);

    digitalWrite(RIGHT_WHEELS_DIRECTION, HIGH);
    analogWrite(RIGHT_WHEELS_SPEED, current_speed);


    digitalWrite(LEFT_WHEELS_DIRECTION, LOW);
    analogWrite(LEFT_WHEELS_SPEED, current_speed);
}


/**
    Méthode permettant de stopper la voiture
*/
void Motors::stop() {
    digitalWrite(GLOBAL_MOTOR, LOW);

    analogWrite(RIGHT_WHEELS_SPEED, 0);
    analogWrite(LEFT_WHEELS_SPEED, 0);
}

void Motors::set_speed(int p_speed) {
    current_speed = p_speed;
}


// Réaliser des figures complexes
void Motors::drive(float leftCoef, float rightCoef) {
    if (leftCoef<-1.0f) leftCoef=-1.0f;
    if (leftCoef>1.0f) leftCoef=1.0f;
    if (rightCoef<-1.0f) rightCoef=-1.0f;
    if (rightCoef>1.0f) rightCoef=1.0f;
    digitalWrite(GLOBAL_MOTOR, HIGH);

    digitalWrite(LEFT_WHEELS_DIRECTION, leftCoef>0.0f?HIGH:LOW);
    analogWrite(LEFT_WHEELS_SPEED, leftCoef*current_speed);
    digitalWrite(RIGHT_WHEELS_DIRECTION, rightCoef>0.0f?HIGH:LOW);
    analogWrite(RIGHT_WHEELS_SPEED, rightCoef*current_speed);
}