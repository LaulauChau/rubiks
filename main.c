#include "rubiks.h"
#include <time.h>


int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);
    printf("\n\n\n");
/*
    int face = 6;

    rubix[face - 1].my_side[0][0].col = select_color(R);
    rubix[face - 1].my_side[0][0].c = 'R';

    rotation_clockwise(rubix, face - 1, 1);

    display_rubiks(rubix);
*/
    return 0;
}
