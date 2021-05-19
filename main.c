#include "rubiks.h"

int main() {
    rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);

    fill_rubiks(rubix);

    /*char couleur[] = "B";

    c_textcolor(select_color(couleur));

    printf("Hello World !\n");*/

    return 0;
}
