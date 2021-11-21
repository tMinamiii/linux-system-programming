#include <stdio.h>
#include <stdlib.h>

void out1 (void) {
    printf("atexit() succeeded! 1 \n");
}
void out2 (void) {
    printf("atexit() succeeded! 2 \n");
}
void out3 (void) {
    printf("atexit() succeeded! 3 \n");
}


int main(void) {
    if (atexit(out1))
        fprintf(stderr, "atexit() failed! 1 \n");
    if (atexit(out2))
        fprintf(stderr, "atexit() failed! 2 \n");
    if (atexit(out3))
        fprintf(stderr, "atexit() failed! 3 \n");
    return 0;
}