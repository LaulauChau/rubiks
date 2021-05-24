#include "rubiks.h"


int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);

    c_textcolor(WHITE);

    int choix, recommencer = 1;
    do {
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("1: Melanger le rubik's\t2: Reinitialiser le rubik's\t3: Vider le rubik's\t4: Jouer\t5: Remplir le rubik's\t6: Quitter\n");
        printf("--------------------------------------------------------------------------------------------------------------------\nChoix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                scramble_rubiks(rubix);
                break;
            case 2:
                free_rubiks(rubix);
                rubix = create_rubiks();
                init_rubiks(rubix);
                break;
            case 3:
                blank_rubiks(rubix);
                break;
            case 4:
                move_rubiks(rubix);
                break;
            case 5:
                fill_rubiks(rubix);
                break;
            case 6:
                recommencer = 0;
                break;
            default:
                printf("Choix incorrect !\n");
                break;
        }

        if (choix != 6) {
            display_rubiks(rubix);
            c_textcolor(WHITE);
            do {
                printf("Voulez-vous retourner au menu ?\n");
                printf("0: Non\t1: Oui\n");
                scanf("%d", &recommencer);
            } while (recommencer < 0 || recommencer > 1);
        }
    } while (recommencer == 1);

    free_rubiks(rubix);

    return 0;
}
