#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int my_system(char* cmd) {
    int status;
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        char *const argv[] = {"sh", "-c", cmd, NULL};
        execv("/bin/sh", argv);
        exit(-1);
    }

    if (waitpid(pid, &status, 0) == -1)
        return -1;
    else if (WIFEXITED(status))
        return WEXITSTATUS(status);

    return -1;
}

int main() {
    do {
        int ret;
        ret = my_system("vmstat");
        if (WIFSIGNALED(ret) &&
        (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) ==  SIGQUIT))
            break;
        sleep(1);
    } while(1);
}