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

  if (!pid) {
    char *const args[] = {"echo", "linux", NULL};
    int ret;
    printf("pid=%d ppid=%d\n", getpid(), getppid());
    sleep(3);
    printf("pid=%d ppid=%d\n", getpid(), getppid());
  } else {
    sleep(1);
    printf("finish parent pid=%d\n", getpid());
  }
}
