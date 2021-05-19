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
            return 12;
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
                rubix[i].my_side[j]->col = select_color(LG);
                rubix[i].my_side[j]->c = 'L';
            }
        }
    }
}

void display_rubiks(rubiks *rubix) {
    int i = 0, j, k, couleur;

    for (j = 0 ; j < LINE ; j++) {
        for (k = 0 ; k < ROW ; k++) {
            if (k == 0) {
                couleur = select_color(rubix[i].my_side[j]->col);
                c_textcolor(couleur);
                printf("      \t%2c", rubix[i].my_side[j]->c);
            } else {
                couleur = select_color(rubix[i].my_side[j]->col);
                c_textcolor(couleur);
                printf("%2c", rubix[i].my_side[j]->c);
            }
        }
        printf("\n");
    }

    printf("\n");
    j = 0;

    while (j < LINE) {
        for (i = 1 ; i < (FACE - 1) ; i++) {
            for (k = 0 ; k < ROW ; k++) {
                couleur = select_color(rubix[i].my_side[j]->col);
                c_textcolor(couleur);
                printf("%2c", rubix[i].my_side[j]->c);
            }
            printf("\t");
        }
        printf("\n");
        j++;
    }

    printf("\n");
    i = 5;

    for (j = 0 ; j < LINE ; j++) {
        for (k = 0 ; k < ROW ; k++) {
            if (k == 0) {
                couleur = select_color(rubix[i].my_side[j]->col);
                c_textcolor(couleur);
                printf("      \t%2c", rubix[i].my_side[j]->c);
            } else {
                couleur = select_color(rubix[i].my_side[j]->col);
                c_textcolor(couleur);
                printf("%2c", rubix[i].my_side[j]->c);
            }
        }
        printf("\n");
    }
}

void blank_rubiks(rubiks *rubix) {
    int i, j;
    for (i = 0 ; i < FACE ; i++) {
        for (j = 0 ; j < LINE ; j++) {
                rubix[i].my_side[j]->col = select_color(LG);
                rubix[i].my_side[j]->c = 'L';
        }
    }
}

void fill_rubiks(rubiks *rubix) {
    int face, cord_x, cord_y, couleur;
    int i, j, booleen = 0;
/*
    for (i = 0 ; i < FACE ; i++) {
        for (j = 0 ; j < LINE ; j++) {
            if (rubix[i].my_side[j]->col == select_color(LG)) {
                printf("\nQuelle face voulez-vous modifier ?\n");
                printf("\t 0. FRONT\n");
                printf("\t 1. BACK\n");
                printf("\t 2. UP\n");
                printf("\t 3. DOWN\n");
                printf("\t 4. LEFT\n");
                printf("\t 5. RIGHT\n");
                printf("Choisissez en entrant le numero de la face : ");
                scanf("%d", &face);

                printf("Veuillez entrer les coordonnees de la case a modifier sous cette forme : 0 0 , 0 1 , 3 4 ...\n");
                scanf("%d%d", &cord_x, &cord_y);

                printf("Veuillez entrer la couleur a affecter :\n");
                printf("\t 0. ROUGE\n");
                printf("\t 1. BLEU\n");
                printf("\t 2. VERT\n");
                printf("\t 3. BLANC\n");
                printf("\t 4. JAUNE\n");
                printf("\t 5. ORANGE\n");
                printf("Choisissez en entrant le numero de la couleur : ");
                scanf("%d", &couleur);

                T_COLOR color = couleur;

                rubix[face].my_side[cord_x]->col = select_color(couleur);
                rubix[face].my_side[cord_x][cord_y].c = color;

                display_rubiks(rubix);
            }
        }
    }
*/

    rubix[0].my_side[1][0].c = 'Z';
    display_rubiks(rubix);
}