// CHAU Laurent MERIAUX Gaetan
// Prototype des fonctions du rubiks
// Definition des structures du rubiks

#ifndef PROJET_C_RUBIKS_H
#define PROJET_C_RUBIKS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "conio.h"

#define FACE 6
#define LINE 3
#define ROW 3

typedef enum {
    FRONT,
    BACK,
    UP,
    DOWN,
    RIGHT,
    LEFT
} T_SIDE;

typedef enum {
    W,  // WHITE
    O,  // ORANGE
    G,  // GREEN
    R,  // RED
    B,  // BLUE
    Y,  // YELLOW
    LG  // LIGHT GRAY
} T_COLOR;

typedef struct {
    T_COLOR col;
    char c;
} box;

typedef struct {
    T_SIDE Tside;
    box **my_side;
} rubiks;


T_COLOR select_color(T_COLOR couleur); // prend une couleur en parametre et retourse sa valeur associee
char colour_to_char(T_COLOR colour); // Prend une couleur et retourne la premiere lettre pour l'affichage
T_SIDE side_to_index(T_SIDE face); // prend un nom de face en parametre et retourne sa position dans le tableau rubiks

rubiks *create_rubiks(); // creer le cube dynamiquement
void init_rubiks(rubiks *rubix); // prend en parametre et qui initialise chaque face a une couleur unique
void display_rubiks(rubiks *rubix); // afficher le rubiks
void blank_rubiks(rubiks *rubix); // griser toutes les cases du cube pour initialisation manuelle
void fill_rubiks(rubiks *rubix); // remplir manuellement le rubiks
void scramble_rubiks(rubiks *rubix); // mouvement aleatoire pour randomiser
void free_rubiks(rubiks *rubix); // liberer la memoire a la fin du programme

void quarter_turn(rubiks *rubix, T_SIDE face, int direction); // Quart de tour d'une face
void half_turn(rubiks *rubix, T_SIDE face); // Demi tour d'une face
void swap_line(rubiks *rubiks, T_SIDE face_1, T_SIDE face_2, int ligne); // Echanger ligne de deux faces

void clockwise(rubiks *rubix, T_SIDE , int nbRotation); // Prend un parametre une face et un nombre de rotation (1:quart de tour, 2:demi tour) et fait une rotion horaire du cube
void anticlockwise(rubiks *rubix, T_SIDE face, int nbRotation); // Rotation anti horaire
void FRONT_clockwise(rubiks *rubix, int nbRotation);
void FRONT_anticlockwise(rubiks *rubix, int nbRotation);
void BACK_clockwise(rubiks *rubix, int nbRotation);
void BACK_anticlockwise(rubiks *rubix, int nbRotation);
void UP_clockwise(rubiks *rubix, int nbRotation);
void UP_anticlockwise(rubiks *rubix, int nbRotation);
void DOWN_clockwise(rubiks *rubix, int nbRotation);
void DOWN_anticlockwise(rubiks *rubix, int nbRotation);
void LEFT_clockwise(rubiks *rubix, int nbRotation);
void LEFT_anticlockwise(rubiks *rubix, int nbRotation);
void RIGHT_clockwise(rubiks *rubix, int nbRotation);
void RIGHT_anticlockwise(rubiks *rubix, int nbRotation);
void horizontal_rotation(rubiks *rubix); // Front deviens Back, Right deviens Left et vice-versa
void vertical_rotation(rubiks *rubix); // Up deviens Down, Front deviens Back et vice-versa

void move_rubiks(rubiks *rubix); // Permettre à l'utilisateur de choisir un des mouvements ci-dessus

#endif //PROJET_C_RUBIKS_H
