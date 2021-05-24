//
// Created by Laurent on 23/04/2021.
//

#include "rubiks.h"

T_COLOR select_color(T_COLOR colour) {
    switch (colour) {
        case R:
            return 12;
        case B:
            return 9;
        case G:
            return 10;
        case W:
            return 15;
        case Y:
            return 14;
        case O:
            return 6;
        default:
            return 8;
    }
}

char colour_to_char(T_COLOR colour) {
    switch (colour) {
        case R:
            return 'R';
        case B:
            return 'B';
        case G:
            return 'G';
        case W:
            return 'W';
        case Y:
            return 'Y';
        case O:
            return 'O';
        default:
            return 'L';
    }
}

T_SIDE side_to_index(T_SIDE face) {
    switch (face) {
        case FRONT:
            return 2;
            break;
        case BACK:
            return 4;
            break;
        case UP:
            return 0;
            break;
        case DOWN:
            return 5;
            break;
        case RIGHT:
            return 3;
            break;
        case LEFT:
            return 1;
            break;
        default:
            return -1;
            break;
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
        rubix[i].Tside = side_to_index(i);
        for (j = 0 ; j < LINE ; j++) {
            for (k = 0 ; k < ROW ; k++) {
                rubix[i].my_side[j][k].col = i;
                rubix[i].my_side[j][k].c = colour_to_char(i);
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
                printf("          \t%4c", rubix[i].my_side[j][k].c);
            } else {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("%4c", rubix[i].my_side[j][k].c);
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
                printf("%4c", rubix[i].my_side[j][k].c);
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
                printf("          \t%4c", rubix[i].my_side[j][k].c);
            } else {
                c_textcolor(select_color(rubix[i].my_side[j][k].col));
                printf("%4c", rubix[i].my_side[j][k].c);
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
    int coord_j, coord_k;
    T_SIDE coord_i;
    int couleur, booleen = 0;
    int color[] = {0, 0, 0, 0, 0, 0};

    int recommencer = 1;
    do {
        c_textcolor(WHITE);
        do {
            printf("Veuillez choisir la face :\n");
            printf("0: FRONT\t1: BACK\t2: UP\t3: DOWN\t4: RIGHT\t5: LEFT\n");
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
            printf("0: WHITE\t1: ORANGE\t2: GREEN\t3: RED\t4: BLUE\t5: YELLOW\n");
            printf("Choisissez en entrant le numero de la couleur : ");
            scanf("%d", &couleur);
        } while (couleur < 0 || couleur > 5);

        rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].col = couleur; // VERT
        rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = colour_to_char(couleur);

        display_rubiks(rubix);

        do {
            printf("Voulez-vous changer une autre case ?\n");
            printf("1: Oui\t0: Non\n");
            printf("Choisissez en entrant le numero de l'action : ");
            scanf("%d", &recommencer);
        } while (recommencer < 0 || recommencer > 1);

    } while (recommencer == 1);
}

void scramble_rubiks(rubiks *rubix) {
    for (int i = 0 ; i < 54 ; i++) {
        clockwise(rubix, rand() % 7, rand() % 3);
    }
}

void free_rubiks(rubiks *rubix) {
    if (rubix != NULL) {
        free(rubix);
    }
}

void quarter_turn(rubiks *rubix, T_SIDE face, int direction) {
    box temp;
    // 1: horaire
    // -1: anti horaire
    // LINE = ROW = 3

    for (int i = 0 ; i < (LINE / 2) ; i++) {
        for (int j = 0 ; j < (LINE - i - 1) ; j++) {
            if (direction == -1) {
                temp = rubix[side_to_index(face)].my_side[i][j];
                rubix[side_to_index(face)].my_side[i][j] = rubix[side_to_index(face)].my_side[j][LINE - i - 1];
                rubix[side_to_index(face)].my_side[j][LINE - i - 1] = rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1];
                rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1] = rubix[side_to_index(face)].my_side[ROW - j - 1][i];
                rubix[side_to_index(face)].my_side[ROW - j - 1][i] = temp;
            } else if (direction == 1) {
                temp = rubix[side_to_index(face)].my_side[i][j];
                rubix[side_to_index(face)].my_side[i][j] = rubix[side_to_index(face)].my_side[ROW - j - 1][i];
                rubix[side_to_index(face)].my_side[ROW - j - 1][i] = rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1];
                rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1] = rubix[side_to_index(face)].my_side[j][LINE - i - 1];
                rubix[side_to_index(face)].my_side[j][LINE - i - 1] = temp;
            }
        }
    }
}

void half_turn(rubiks *rubix, T_SIDE face) {
    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, face, 1);
    }
}

void swap_line(rubiks *rubix, T_SIDE face_1, T_SIDE face_2, int ligne) {
    box temp;
    for (int j = 0 ; j < ROW ; j++) {
        temp = rubix[side_to_index(face_1)].my_side[ligne][j];
        rubix[side_to_index(face_1)].my_side[ligne][j] = rubix[side_to_index(face_2)].my_side[ligne][j];
        rubix[side_to_index(face_2)].my_side[ligne][j] = temp;
    }
}

void FRONT_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, FRONT, clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, clockwise);
        quarter_turn(rubix, RIGHT, -clockwise);
        half_turn(rubix, DOWN);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, RIGHT, 2);
                swap_line(rubix, UP, LEFT, 2);
                swap_line(rubix, LEFT, DOWN, 2);
            }

            clockwise *= -1;
        }
    }
}

void FRONT_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, FRONT, -clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, clockwise);
        quarter_turn(rubix, RIGHT, -clockwise);
        half_turn(rubix, DOWN);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, RIGHT, 2);
                swap_line(rubix, RIGHT, DOWN, 2);
                swap_line(rubix, DOWN, LEFT, 2);
            }
        }
    }
}

void BACK_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, BACK, clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, RIGHT, clockwise);
        quarter_turn(rubix, LEFT, -clockwise);
        half_turn(rubix, UP);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, LEFT, 2);
                swap_line(rubix, UP, RIGHT, 2);
                swap_line(rubix, RIGHT, DOWN, 2);
            }

            clockwise *= -1;
        }
    }
}

void BACK_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, BACK, -clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, RIGHT, clockwise);
        quarter_turn(rubix, LEFT, -clockwise);
        half_turn(rubix, UP);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, LEFT, 2);
                swap_line(rubix, LEFT, DOWN, 2);
                swap_line(rubix, DOWN, RIGHT, 2);
            }
        }
    }
}

void UP_clockwise(rubiks *rubix, int nbRotation) {
    quarter_turn(rubix, UP, 1);

    for (int i = 0 ; i < 2 ; i++) {
        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, BACK, RIGHT, 0);
                swap_line(rubix, BACK, LEFT, 0);
                swap_line(rubix, LEFT, FRONT, 0);
            }
        }
    }
}

void UP_anticlockwise(rubiks *rubix, int nbRotation) {
    quarter_turn(rubix, UP, -1);

    for (int i = 0 ; i < 2 ; i++) {
        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, BACK, RIGHT, 0);
                swap_line(rubix, RIGHT, FRONT, 0);
                swap_line(rubix, FRONT, LEFT, 0);
            }
        }
    }
}

void DOWN_clockwise(rubiks *rubix, int nbRotation) {
    quarter_turn(rubix, DOWN, 1);

    for (int i = 0 ; i < 2 ; i++) {
        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, FRONT, LEFT, 2);
                swap_line(rubix, FRONT, RIGHT, 2);
                swap_line(rubix, RIGHT, BACK, 2);
            }
        }
    }
}

void DOWN_anticlockwise(rubiks *rubix, int nbRotation) {
    quarter_turn(rubix, DOWN, -1);

    for (int i = 0 ; i < 2 ; i++) {
        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, FRONT, LEFT, 2);
                swap_line(rubix, LEFT, BACK, 2);
                swap_line(rubix, BACK, RIGHT, 2);
            }
        }
    }
}

void LEFT_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, LEFT, clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, BACK, clockwise);
        quarter_turn(rubix, UP, -clockwise);
        quarter_turn(rubix, FRONT, -clockwise);
        quarter_turn(rubix, DOWN, -clockwise);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, FRONT, 2);
                swap_line(rubix, UP, BACK, 2);
                swap_line(rubix, BACK, DOWN, 2);
            }

            clockwise *= -1;
        }
    }
}

void LEFT_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, LEFT, -clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, BACK, clockwise);
        quarter_turn(rubix, UP, -clockwise);
        quarter_turn(rubix, FRONT, -clockwise);
        quarter_turn(rubix, DOWN, -clockwise);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, FRONT, 2);
                swap_line(rubix, FRONT, DOWN, 2);
                swap_line(rubix, DOWN, BACK, 2);
            }
        }
    }
}

void RIGHT_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, RIGHT, clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, FRONT, clockwise);
        quarter_turn(rubix, UP, clockwise);
        quarter_turn(rubix, BACK, -clockwise);
        quarter_turn(rubix, DOWN, clockwise);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, BACK, 2);
                swap_line(rubix, UP, FRONT, 2);
                swap_line(rubix, FRONT, DOWN, 2);
            }

            clockwise *= -1;
        }
    }
}

void RIGHT_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    quarter_turn(rubix, RIGHT, -clockwise);

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, FRONT, clockwise);
        quarter_turn(rubix, UP, clockwise);
        quarter_turn(rubix, BACK, -clockwise);
        quarter_turn(rubix, DOWN, clockwise);

        if (i == 0) {
            for (int j = 0; j < nbRotation; j++) {
                swap_line(rubix, UP, BACK, 2);
                swap_line(rubix, BACK, DOWN, 2);
                swap_line(rubix, DOWN, FRONT, 2);
            }
        }
    }
}

void horizontal_rotation(rubiks *rubix) {
    for (int i = 0 ; i < LINE ; i++) {
        swap_line(rubix, FRONT, BACK, i);
        swap_line(rubix, LEFT, RIGHT, i);
    }
}

void vertical_rotation(rubiks *rubix) {
    for (int i = 0 ; i < LINE ; i++) {
        swap_line(rubix, DOWN, UP, i);
        swap_line(rubix, FRONT, BACK, i);
    }
}

void clockwise(rubiks *rubix, T_SIDE face, int nbRotation) {
    switch (face) {
        case FRONT:
            FRONT_clockwise(rubix, nbRotation);
            break;
        case BACK:
            BACK_clockwise(rubix, nbRotation);
            break;
        case UP:
            UP_clockwise(rubix, nbRotation);
            break;
        case DOWN:
            DOWN_clockwise(rubix, nbRotation);
            break;
        case LEFT:
            LEFT_clockwise(rubix, nbRotation);
            break;
        case RIGHT:
            RIGHT_clockwise(rubix, nbRotation);
            break;
    }
}

void anticlockwise(rubiks *rubix, T_SIDE face, int nbRotation) {
    switch (face) {
        case FRONT:
            FRONT_anticlockwise(rubix, nbRotation);
            break;
        case BACK:
            BACK_anticlockwise(rubix, nbRotation);
            break;
        case UP:
            UP_anticlockwise(rubix, nbRotation);
            break;
        case DOWN:
            DOWN_anticlockwise(rubix, nbRotation);
            break;
        case LEFT:
            LEFT_anticlockwise(rubix, nbRotation);
            break;
        case RIGHT:
            RIGHT_anticlockwise(rubix, nbRotation);
            break;
    }
}

void move_rubiks(rubiks *rubix) {
    T_SIDE face;
    int recommencer = 1;

    do {
        do {
            printf("Veuillez choisir la face :\n");
            printf("0: FRONT\t1: BACK\t2: UP\t3: DOWN\t4: RIGHT\t5: LEFT\n");
            scanf("%d", &face);
        } while (face < 0 || face > 5);

        int typeRotation;
        do {
            printf("Veuillez choisir le type de rotation :\n");
            printf("1: Horaire\t2: Antihoraire\t3: Rotation horizontal\t4: Rotation verticale\n");
            scanf("%d", &typeRotation);
        } while (typeRotation < 1 || typeRotation > 4);

        if (typeRotation < 3) {
            int nbRotation;
            do {
                printf("Veuillez choisir le nombre de rotation :\n");
                printf("1: Quart de tour\t2: Demi tour\n");
                scanf("%d", &nbRotation);
            } while (nbRotation < 1 || nbRotation > 2);

            if (typeRotation == 1) {
                clockwise(rubix, face, nbRotation);
            } else {
                anticlockwise(rubix, face, nbRotation);
            }
        } else {
            if (typeRotation == 3) {
                horizontal_rotation(rubix);
            } else {
                vertical_rotation(rubix);
            }
        }

        display_rubiks(rubix);

        printf("Voulez-vous faire un autre mouvement ?\n");
        printf("1: Oui\t0: Non\n");
        scanf("%d", &recommencer);
    } while (recommencer == 1);
}