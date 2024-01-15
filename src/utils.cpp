#include "../include/utils.hpp"
#include "../include/lightsensor.hpp"
#include "../include/motors.hpp"
#include <Arduino.h>

/* -- Contient des fonctions utiles au projet -- */

/* 
    Fonction qui en fonction des paramètres R,G,B, renvoie un uint32_t
    elle provient des TP
*/
uint32_t color(uint8_t r, uint8_t g, uint8_t b){
    return (((uint32_t)r <<16) | ((uint32_t)g << 8) | b);
}


/*
    Fonction qui retourne un code décimal basé sur les valeurs renvoyés par la fonction detect() de
    chacun des trois capteurs.

    Voici un tableau explicatif :

    En nous basant sur cette fiche technique.

    GAUCHE    CENTRE    DROITE    RETURN VALUE
    false     false     false          0  
    true      false     false          1  
    false     true      false          2  
    true      true      false          3         
    false     false     true           4  
    true      false     true           5  
    false     true      true           6   
    true      true      true           7  
   

    LEFT, CENTER et RIGHT correspondent aux valeurs respectivement renvoyées par LEFT.detecT(),
    CENTER.detect() et RIGHT.detect().
*/


int get_todo() {
    // On initialise 3 objets représentant les 3 capteurs de lumière

    LightSensor LEFT(A2); // Capteur de lumière à gauche
    LightSensor CENTER(A1); // Capteur de lumière au centre
    LightSensor RIGHT(A0); // Capteur de lumière à droite

    // On génére le code
    return LEFT.detect() * 1 
            + 
           CENTER.detect() * 2 
            + 
           RIGHT.detect() * 4;
}
