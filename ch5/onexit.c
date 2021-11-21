#include <stdio.h>
#include <stdlib.h>

void out (int status, void *arg) {
    printf("on_exit() succeeded! %s \n", (char *)arg);
}


int main(void) {
    if (on_exit(out, "on exit 1"))
        fprintf(stderr, "on_exit() failed! 1 \n");
    if (on_exit(out, "on exit 2"))
        fprintf(stderr, "on_exit() failed! 2 \n");
    if (on_exit(out, "on exit 3"))
        fprintf(stderr, "on_exit() failed! 3 \n");
    return 0;
}