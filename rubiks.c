//
// Created by Laurent on 23/04/2021.
//

#include "rubiks.h"

T_COLOR select_color(T_COLOR couleur) {
    switch (couleur) {
        case R:
            return 12;
            break;
        case B:
            return 9;
            break;
        case G:
            return 10;
            break;
        case W:
            return 15;
            break;
        case Y:
            return 14;
            break;
        case O:
            return 6;
            break;
        default:
            return 8;
            break;
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
                rubix[i].my_side[j][k].col = select_color(LG); // 6: Light Gray
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
    int coord_j, coord_k;
    T_SIDE coord_i;
    T_COLOR couleur;

    int recommencer = 1;
    do {
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
            printf("0: RED\t1: BLUE\t2: GREEN\t3: WHITE\t4: YELLOW\t5: ORANGE\n");
            printf("Choisissez en entrant le numero de la couleur : ");
            scanf("%d", &couleur);
        } while (couleur < 0 || couleur > 5);

        rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].col = select_color(couleur); // VERT

        switch (couleur) {
            case 0:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'R';
                break;
            case 1:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'B';
                break;
            case 2:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'G';
                break;
            case 3:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'W';
                break;
            case 4:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'Y';
                break;
            case 5:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'O';
                break;
            default:
                rubix[side_to_index(coord_i)].my_side[coord_j][coord_k].c = 'L';
                break;
        }

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
    int coord_i, coord_j, coord_k;
    int coord_i2, coord_j2, coord_k2;

    for (int i = 0 ; i < 54 ; i++) {
        srand(time(NULL));

        coord_i = rand() % FACE;
        coord_j = rand() % LINE;
        coord_k = rand() % ROW;

        coord_i2 = rand() % FACE;
        coord_j2 = rand() % LINE;
        coord_k2 = rand() % ROW;
        rubix[coord_i].my_side[coord_j][coord_k] = rubix[coord_i2].my_side[coord_j2][coord_k2];
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
        for (int j = 0 ; j < (LINE - i) ; j++) {
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
    int clockwise = -1;

    quarter_turn(rubix, FRONT, clockwise);

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

            clockwise *= -1;
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
    int clockwise = -1;

    quarter_turn(rubix, BACK, clockwise);

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

            clockwise *= -1;
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
    int clockwise = -1;

    quarter_turn(rubix, LEFT, clockwise);

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

            clockwise *= -1;
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
    int clockwise = -1;

    quarter_turn(rubix, RIGHT, clockwise);

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

            clockwise *= -1;
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
