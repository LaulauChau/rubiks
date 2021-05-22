#include "rubiks.h"
#include <time.h>


int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);
    printf("\n\n\n");
    fill_rubiks(rubix);*/

    T_COLOR couleur;
    T_SIDE coord_i;
    printf("Veuillez choisir la couleur :\n");
    printf("0: RED\t1: BLUE\t2: GREEN\t3: WHITE\t4: YELLOW\t5: ORANGE\n");
    printf("Choisissez en entrant le numero de la couleur : ");
    scanf("%d", &couleur);

    printf("Veuillez choisir la face :\n");
    printf("0: UP\t1: LEFT\t2: FRONT\t3: RIGHT\t4: BACK\t5: DOWN\n");
    printf("Choisissez en entrant le numero de la face : ");
    scanf("%d", &coord_i);

    c_textcolor(select_color(couleur));

    printf("Hello World !\n");
    printf("Face %d\n", side_to_index(coord_i));

    rubix[face - 1].my_side[0][0].col = select_color(R);
    rubix[face - 1].my_side[0][0].c = 'R';

    rotation_clockwise(rubix, face - 1, 1);

    display_rubiks(rubix);
*/
    return 0;
}
