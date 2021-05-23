#include "rubiks.h"
#include <time.h>


int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);
    printf("\n\n\n");
    fill_rubiks(rubix);

    FRONT_clockwise(rubix, 1);
    display_rubiks(rubix);
    return 0;
}
