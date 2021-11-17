#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int status;
  pid_t pid;
  pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  /* the child... */
  if (!pid) {
    char *const args[] = {"echo", "linux", NULL};
    int ret;
    printf("ppid=%d\n", getppid());
    sleep(5);
    printf("ppid=%d\n", getppid());
    ret = execv("/bin/echo", args);
    if (ret == -1) {
      perror("execv");
      exit(1);
    }
  } else {
    wait(&status);
    printf("parent\n");
  }
}
