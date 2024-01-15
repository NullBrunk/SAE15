#include <Arduino.h>

// Signature de la fonction color
uint32_t color(uint8_t r, uint8_t g, uint8_t b);

/* VARIABLES */
const uint32_t RED = color(255, 0, 0); 
const uint32_t GREEN = color(0, 255, 0);
const uint32_t ORANGE = color(255, 100, 0); 
const uint32_t BLEU = color(0, 0, 255);
const uint32_t CYAN = color(0, 255, 255);
const uint32_t YELLOW = color(255, 255, 0);

/* 
    On remplit le tableau avec les couleurs demandées dans l'énoncé,
    dans l'ordre demandé
*/
const uint32_t COLORS[9] = { RED, GREEN, BLEU, ORANGE, BLEU, YELLOW, BLEU, CYAN, RED };

// Signature de la fonction get todo qui permet de recuperer un code spécial en fonction des 
// valeurs renvoyés par la méthode detect() sur chaque capteur
int get_todo();
