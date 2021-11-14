#include <unistd.h>
#include <stdio.h>


int main() {
    int ret;
    char *const args[] = {"vim", "./hooks.txt", NULL};
    ret = execvp("vim", args);
    if (ret == -1) {
        perror("execvp");
    }
}