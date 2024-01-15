#include "include/motors.hpp"
#include "include/utils.hpp"
#include <FastLED.h>

// Le nombre de LED RGB à controler
#define NUM_LEDS 1
// Le PIN de la LED RGB à contrôler
#define PIN_RBGLED 4

// i est notre compteur qui nous permettera d'afficher tour à tour les couleurs du tableau COLORS (voir fichier utils.hpp)
// sur notre led
int i = 0;

// Le nombre de tour qu'a parcouru notre Arduino. Un tour est un aller. Un aller-retour correspond donc à deux tours
int tour = 0;

// Instanciation de la classe Motors, permettant de déplacer le véhicule dans la direction que l'on veut avec
// une vitesse 125
Motors motors(125);


CRGB leds[NUM_LEDS];

// Fonction permettant d'afficher la valeur de color sur notre LED RGB
void show(uint32_t color) {
    FastLED.showColor(color);
}


void setup() {
    // Code de TP pour initialiser la LED
    FastLED.addLeds<NEOPIXEL,PIN_RBGLED>(leds, NUM_LEDS);
    FastLED.setBrightness(20);

    // On commence par afficher la première couleur du tableau sur notre LED (rouge)
    show(COLORS[i]);

    // On attend deux secondes
    delay(2000);

    /*
        Au lieu de faire 
        
        ```
        i++; 
        show(COLORS[i]);
        ```
        
        on peut directement faire une préincrémentation, suivie de l'appel à la fonction show.
        On affiche donc ici la deuxieme couleur du tableau (VERT)
    */
    show(COLORS[++i]);

    Serial.begin(9600);
}

void loop() {
    
    /*
        On recupère un code spécial grâce à la fonction get_todo(), qui nous permettra de savoir quoi
        faire 
    */ 
    int todo = get_todo();

    // Si get_todo() renvoie 1 -> Le capteur de gauche sur la ligne, les deux autres hors ligne
    if(todo == 1) {
        motors.drive(0, 1);
    }
    
    // Si get_todo() renvoie 4 -> Le capteur de droite sur la ligne, les deux autres hors ligne
    else if(todo == 4) {
        motors.drive(1, 0);
    }

    /* 
        Si get_todo() renvoie 2 -> Le capteur du centre est sur la ligne  
        Si get_todo() renvoie 3 -> Le capteur de gauche && le capteur du centre sont sur la ligne
        Si get_todo() renvoie 6 -> Le capteur de droite && le capteur du centre sont sur la ligne
    */
    else if(todo == 2 || todo == 3 || todo == 6) {
        motors.drive(1, 1);
    } 
    
    // Si get_todo() renvoie 7 -> Les trois capteurs détéctent du noir, il faut donc faire demi-tour
    else if(todo == 7) {

        // On incrémente la couleur juste avant le début du demi-tour, (la LED devient bleue)
        show(COLORS[++i]);

        // On incrémente la valeur du nombre de tour
        // On incrémente tour ici, car si on l'incrémente après le demi-tour, on ne pourra pas
        // respecter la consigne qui nous demande d'arreter le robot AVANT le demi-tour du dernier
        // tour
        tour++;

        // Si on a fait 4 tours, (ici un tour est soit un aller soit un retour, donc 4 allers/retours = 2 allers-retours)
        if(tour == 4) {
            
            // On stop la voiture et on quitte la fonction void avec un exit(0)
            motors.stop();
            exit(0);
        }

        /* 
            Tant que la fonction get_todo ne nous renvoie pas un 2
            (2 = le capteur du centre sur noir)
            on continue à tourner, effectuant ainsi un demi-tour
        */
        while(get_todo() != 2) {
            motors.right();
        }

        // On passe à la couleur suivante juste après le demi-tour
        // comme la consigne le demande
        show(COLORS[++i]);        
    }
}
