//
// Created by Laurent on 23/04/2021.
//

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
    R,  // RED
    B,  // BLUE
    G,  // GREEN
    W,  // WHITE
    Y,  // YELLOW
    O,  // ORANGE
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
T_SIDE side_to_index(T_SIDE face); // prend un nom de face en parametre et retourne sa position dans le tableau rubiks

rubiks *create_rubiks(); // creer le cube dynamiquement
void init_rubiks(rubiks *rubix); // prend en parametre et qui initialise chaque face a une couleur unique
void display_rubiks(rubiks *rubix); // afficher le rubiks
void blank_rubiks(rubiks *rubix); // griser toutes les cases du cube pour initialisation manuelle
void fill_rubiks(rubiks *rubix); // remplir manuellement le rubiks
void scramble_rubiks(); // mouvement aleatoire pour randomiser
void free_rubiks(); // liberer la memoire a la fin du programme

void quarter_turn(rubiks *rubix, T_SIDE face, int direction); // Quart de tour d'une face
void half_turn(rubiks *rubix, T_SIDE face); // Demi tour d'une face
void swap_line(rubiks *rubiks, T_SIDE face_1, T_SIDE face_2, int ligne); // Echanger ligne de deux faces

void FRONT_clockwise(rubiks *rubix, int nbRotation); // Rotation horaire
void FRONT_anticlockwise(rubiks *rubix, int nbRotation); // Rotation antihoraire
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
void horizontal_rotation(rubiks *rubix); // Rotation horizontale
void vertical_rotation(rubiks *rubix); // Rotation vertical

#endif //PROJET_C_RUBIKS_H
