#include "rubiks.h"


int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);
    printf("\n\n\n");

    move_rubiks(rubix);

    display_rubiks(rubix);

    return 0;
}
