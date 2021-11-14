#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid == -1)
        perror("fork");

    /* the child... */
    if (!pid) {
        const char *args[] = {"windlass", NULL};
        int ret;

        ret = execv("/bin/windlass", args);
        if (ret == -1) {
            perror("execv");
            exit(1);
        }
    }
}