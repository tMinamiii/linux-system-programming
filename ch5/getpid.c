#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("My pid=%d\n", getpid());
    printf("My parent's pid=%d\n", getppid());
}