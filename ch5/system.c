#define _XOPEN_SOURCE
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    do {
        int ret;
        ret = system("vmstat");
        if (WIFSIGNALED(ret) &&
        (WTERMSIG(ret) == SIGINT || WTERMSIG(ret) ==  SIGQUIT))
            break;
        sleep(1);
    } while(1);
}