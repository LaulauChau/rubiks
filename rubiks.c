//
// Created by Laurent on 23/04/2021.
//

#include "rubiks.h"

int select_color(T_COLOR couleur) {
    switch (couleur) {
        case R:
            return 4;
        case B:
            return 1;
        case G:
            return 2;
        case W:
            return 15;
        case Y:
            return 14;
        case O:
            return 6;
        default:
            return 7;
    }
}

int side_to_index(T_SIDE face) {
    switch (face) {
        case UP:
            return 0;
        case LEFT:
            return 1;
        case FRONT:
            return 2;
        case RIGHT:
            return 3;
        case BACK:
            return 4;
        case DOWN:
            return 5;
        default:
            return -1;
    }
}

rubiks *create_rubiks() {
    int i, j;
    rubiks *rubix;
    rubix = (rubiks*) malloc (FACE * sizeof(rubiks));
    for (i = 0 ; i < FACE ; i++) {
        rubix[i].my_side = (box**) malloc (LINE * sizeof(box*));
        for (j = 0 ; j < LINE ; j++) {
            rubix[i].my_side[j] = (box*) malloc (ROW * sizeof(box));
        }
    }
    return rubix;
}

void init_rubiks(rubiks *rubix) {
    int i, j, k;
    for (i = 0 ; i < FACE ; i++) {
        for (j = 0 ; j < LINE ; j++) {
            for (k = 0 ; k < ROW ; k++) {
                rubix[i].my_side[j][k].col = select_color(LG);
                rubix[i].my_side[j][k].c = 'L';
            }
        }
    }
}

void display_rubiks(rubiks *rubix) {
    int i = 0, j, k;
    // Affichage Face UP
    for (j = 0 ; j < LINE ; j++) {
        for (k = 0 ; k < ROW ; k++) {
            if (k == 0) {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("      \t%2c", rubix[i].my_side[j][k].c);
            } else {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("%2c", rubix[i].my_side[j][k].c);
            }
        }
        printf("\n");
    }

    printf("\n");

    // Affichage LEFT FRONT RIGHT BACK
    j = 0;

    while (j < LINE) {
        for (i = 1 ; i < (FACE - 1) ; i++) {
            for (k = 0 ; k < ROW ; k++) {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("%2c", rubix[i].my_side[j][k].c);
            }
            printf("\t");
        }
        printf("\n");
        j++;
    }

    printf("\n");

    // Affichage DOWN
    i = 5;
    for (j = 0 ; j < LINE ; j++) {
        for (k = 0 ; k < ROW ; k++) {
            if (k == 0) {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("      \t%2c", rubix[i].my_side[j][k].c);
            } else {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("%2c", rubix[i].my_side[j][k].c);
            }
        }
        printf("\n");
    }
}

void blank_rubiks(rubiks *rubix) {
    int i, j, k;
    for (i = 0 ; i < FACE ; i++) {
        for (j = 0 ; j < LINE ; j++) {
            for (k = 0 ; k < ROW ; k++) {
                rubix[i].my_side[j][k].col = select_color(LG);
                rubix[i].my_side[j][k].c = 'L';
            }
        }
    }
}

void fill_rubiks(rubiks *rubix) {
    int i, j, k;
    int coord_i, coord_j, coord_k, couleur;
    int recommencer = 1;
    do {
        c_textcolor(select_color(3));
        do {
            printf("Veuillez choisir la face :\n");
            printf("0. UP\n");
            printf("1. LEFT\n");
            printf("2. FRONT\n");
            printf("3. RIGHT\n");
            printf("4. BACK\n");
            printf("5. DOWN\n");
            printf("Choisissez en entrant le numero de la face : ");
            scanf("%d", &coord_i);
        } while (coord_i < 0 || coord_i > 5);

        do {
            printf("Veuillez choisir la case :\n");
            printf("Position x : ");
            scanf("%d", &coord_j);
        } while (coord_j < 0 || coord_j > 2);

        do {
            printf("Position y : ");
            scanf("%d", &coord_k);
        } while (coord_k < 0 || coord_k > 2);

        do {
            printf("Veuillez choisir la couleur :\n");
            printf("0. RED\n");
            printf("1. BLUE\n");
            printf("2. GREEN\n");
            printf("3. WHITE\n");
            printf("4. YELLOW\n");
            printf("5. ORANGE\n");
            printf("Choisissez en entrant le numero de la couleur : ");
            scanf("%d", &couleur);
        } while (couleur < 0 || couleur > 5);

        rubix[coord_i].my_side[coord_j][coord_k].col = select_color(couleur); // VERT

        switch (couleur) {
            case 0:
                c_textcolor(select_color(couleur));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'R';
                break;
            case 1:
                c_textcolor(select_color(couleur));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'B';
                break;
            case 2:
                c_textcolor(select_color(couleur));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'G';
                break;
            case 3:
                c_textcolor(select_color(couleur));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'W';
                break;
            case 4:
                c_textcolor(select_color(couleur));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'Y';
                break;
            case 5:
                c_textcolor(select_color(rubix[coord_i].my_side[coord_j][coord_k].col));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'O';
                break;
            default:
                c_textcolor(select_color(LG));
                rubix[coord_i].my_side[coord_j][coord_k].c = 'L';
                break;
        }

        display_rubiks(rubix);

        printf("Voulez-vous changer une autre case ? (1/0)");
        scanf("%d", &recommencer);
    } while (recommencer == 1);
}

void scramble_rubiks(rubiks * rubix) {
    int coord_i, coord_j, coord_k;
    int coord_i2, coord_j2, coord_k2;
    srand(time(NULL));

    for (int i = 0 ; i < 54 ; i++) {
        coord_i = rand() % 6;
        coord_j = rand() % 3;
        coord_k = rand() % 3;

        coord_i2 = rand() % 6;
        coord_j2 = rand() % 3;
        coord_k2 = rand() % 3;
        rubix[coord_i].my_side[coord_j][coord_k] = rubix[coord_i2].my_side[coord_j2][coord_k2];
    }
}