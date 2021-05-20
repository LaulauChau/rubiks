#include "rubiks.h"
#include <time.h>


int main() {
    /*rubiks *rubix = create_rubiks();
    init_rubiks(rubix);
    display_rubiks(rubix);
    printf("\n\n\n");
    fill_rubiks(rubix);*/
    srand(time(NULL));
    printf("%d", rand() % 5);

    return 0;
}
