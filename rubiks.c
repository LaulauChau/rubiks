//
// Created by Laurent on 23/04/2021.
//

#include "rubiks.h"

int select_color(T_COLOR couleur) {
    switch (couleur) {
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

int side_to_index(T_SIDE face) {
    /*switch (face) {
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
    }*/
    return face;
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
            printf("0: UP\t1: LEFT\t2: FRONT\t3: RIGHT\t4: BACK\t5: DOWN\n");
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
            printf("1: Oui\t0: Non");
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
    // 1: horaire
    // -1: anti horaire
    // LINE = ROW = 3

    for (int i = 0 ; i < LINE ; i++) {
        for (int j = 0 ; j < ROW ; j++) {
            if (direction == 1) {
                box temp = rubix[side_to_index(face)].my_side[i][j];
                rubix[side_to_index(face)].my_side[i][j] = rubix[side_to_index(face)].my_side[j][LINE - i - 1];
                rubix[side_to_index(face)].my_side[j][LINE - i - 1] = rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1];
                rubix[side_to_index(face)].my_side[LINE - i - 1][ROW - j - 1] = rubix[side_to_index(face)].my_side[ROW - j - 1][i];
                rubix[side_to_index(face)].my_side[ROW - j - 1][i] = temp;
            } else if (direction == -1) {
                box temp = rubix[side_to_index(face)].my_side[i][j];
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
    for (int j = 0 ; j < ROW ; j++) {
        box temp = rubix[side_to_index(face_1)].my_side[ligne][j];
        rubix[side_to_index(face_1)].my_side[ligne][j] = rubix[side_to_index(face_2)].my_side[ligne][j];
        rubix[side_to_index(face_2)].my_side[ligne][j] = temp;
    }
}

void crown(rubiks *rubix, T_SIDE left, T_SIDE up, T_SIDE right, T_SIDE down, int direction) {
    // 1: Rotation horaire, -1: Rotation antihoraire
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, left, clockwise);
        quarter_turn(rubix, right, -clockwise);
        half_turn(rubix, down);

        if (i == 0) {
            // 1: Rotation horaire, 2: Rotation antihoraire
            if (direction == 1) {
                swap_line(rubix, up, right, 2);
                swap_line(rubix, up, left, 2);
                swap_line(rubix, left, down, 2);
            } else if (direction == 2) {
                swap_line(rubix, up, right, 2);
                swap_line(rubix, right, down, 2);
                swap_line(rubix, down, left, 2);
            }
            clockwise *= -1;
        }
    }
}

void FRONT_clockwise(rubiks *rubix, int nbRotation) {
    for (int i = 0 ; i < nbRotation ; i++) {
        crown(rubix, LEFT, UP, RIGHT, DOWN, 1);
    }
}

void FRONT_anticlockwise(rubiks *rubix, int nbRotation) {
    for (int i = 0 ; i < nbRotation ; i++) {
        crown(rubix, LEFT, UP, RIGHT, DOWN, -1);
    }
}

void BACK_clockwise(rubiks *rubix, int nbRotation) {
    for (int i = 0 ; i < 2 ; i++) {
        half_turn(rubix, RIGHT);
        half_turn(rubix, UP);
        half_turn(rubix, LEFT);
        half_turn(rubix, DOWN);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, RIGHT, UP, LEFT, DOWN, 1);
            }
        }
    }
}

void BACK_anticlockwise(rubiks *rubix, int nbRotation) {
    for (int i = 0 ; i < 2 ; i++) {
        half_turn(rubix, RIGHT);
        half_turn(rubix, UP);
        half_turn(rubix, LEFT);
        half_turn(rubix, DOWN);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, RIGHT, UP, LEFT, DOWN, -1);
            }
        }
    }
}

void UP_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, -clockwise);
        half_turn(rubix, BACK);
        quarter_turn(rubix, RIGHT, clockwise);
        quarter_turn(rubix, FRONT, clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, LEFT, BACK, RIGHT, FRONT, 1);
            }

            clockwise *= -1;
        }
    }
}

void UP_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, -clockwise);
        half_turn(rubix, BACK);
        quarter_turn(rubix, RIGHT, clockwise);
        quarter_turn(rubix, FRONT, clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, LEFT, BACK, RIGHT, FRONT, -1);
            }

            clockwise *= -1;
        }
    }
}

void DOWN_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, clockwise);
        quarter_turn(rubix, RIGHT, -clockwise);
        quarter_turn(rubix, BACK, -clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, LEFT, FRONT, RIGHT, BACK, 1);
            }

            clockwise *= -1;
        }
    }
}

void DOWN_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, LEFT, clockwise);
        quarter_turn(rubix, RIGHT, -clockwise);
        quarter_turn(rubix, BACK, -clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, LEFT, FRONT, RIGHT, BACK, -1);
            }

            clockwise *= -1;
        }
    }
}

void LEFT_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, UP, clockwise);
        quarter_turn(rubix, DOWN, -clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, BACK, UP, FRONT, DOWN, 1);
            }

            clockwise *= -1;
        }
    }
}

void LEFT_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, UP, clockwise);
        quarter_turn(rubix, DOWN, -clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, BACK, UP, FRONT, DOWN, -1);
            }

            clockwise *= -1;
        }
    }
}

void RIGHT_clockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, UP, -clockwise);
        quarter_turn(rubix, DOWN, clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, FRONT, UP, BACK, DOWN, 1);
            }

            clockwise *= -1;
        }
    }
}

void RIGHT_anticlockwise(rubiks *rubix, int nbRotation) {
    int clockwise = 1;

    for (int i = 0 ; i < 2 ; i++) {
        quarter_turn(rubix, UP, -clockwise);
        quarter_turn(rubix, DOWN, clockwise);

        if (i == 0) {
            for (int j = 0 ; j < nbRotation ; j++) {
                crown(rubix, FRONT, UP, BACK, DOWN, -1);
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

void rotation_clockwise(rubiks *rubix, int face, int rotation) {
    if (rotation == 1) {
        for (int i = 0; i < (LINE / 2); i++) {
            for (int j = 0; j < (LINE - i - 1); j++) {
                box temp = rubix[side_to_index(face)].my_side[i][j];
                rubix[face].my_side[i][j] = rubix[face].my_side[LINE - 1 - j][i];
                rubix[face].my_side[LINE - 1 - j][i] = rubix[face].my_side[LINE - 1 - i][LINE - 1 - j];
                rubix[face].my_side[LINE - 1 - i][LINE - 1 - j] = rubix[face].my_side[j][LINE - 1 - i];
                rubix[face].my_side[j][LINE - 1 - i] = temp;
            }
        }
    } else {
        for (int k = 0 ; k < 2 ; k++) {
            for (int i = 0; i < (LINE / 2); i++) {
                for (int j = 0; j < (LINE - i - 1); j++) {
                    box temp = rubix[side_to_index(face)].my_side[i][j];
                    rubix[side_to_index(face)].my_side[i][j] = rubix[side_to_index(face)].my_side[LINE - 1 - j][i];
                    rubix[side_to_index(face)].my_side[LINE - 1 - j][i] = rubix[side_to_index(face)].my_side[LINE - 1 - i][LINE - 1 - j];
                    rubix[side_to_index(face)].my_side[LINE - 1 - i][LINE - 1 - j] = rubix[side_to_index(face)].my_side[j][LINE - 1 - i];
                    rubix[side_to_index(face)].my_side[j][LINE - 1 - i] = temp;
                }
            }
        }
    }
}