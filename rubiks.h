//
// Created by Laurent on 23/04/2021.
//

#ifndef PROJET_C_RUBIKS_H
#define PROJET_C_RUBIKS_H

#include <stdio.h>
#include <stdlib.h>

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
    R, // RIGHT 4
    B, // UP 2
    G, // DOWN 3
    W, // FRONT 0
    Y, // BACK 1
    O, // LEFT 5
    LG
} T_COLOR;

typedef struct {
    T_COLOR col;
    char c;
} box;

typedef struct {
    T_SIDE Tside;
    box **my_side;
} rubiks;


int select_color(T_COLOR couleur); // prend une couleur en parametre et retourse sa valeur associee
int side_to_index(T_SIDE face); // prend un nom de face en parametre et retourne sa position dans le tableau rubiks

rubiks *create_rubiks(); // creer le cube dynamiquement
void init_rubiks(rubiks *rubix); // prend en parametre et qui initialise chaque face a une couleur unique
void display_rubiks(); // afficher le rubiks
void blank_rubiks(); // griser toutes les cases du cube pour initialisation manuelle
void fill_rubiks(); // remplir manuellement le rubiks
void scramble_rubiks(); // mouvement aleatoire pour randomiser
void free_rubiks(); // liberer la memoire a la fin du programme

#endif //PROJET_C_RUBIKS_H
