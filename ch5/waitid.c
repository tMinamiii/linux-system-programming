#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1;
  pid1 = fork();
  if (!pid1) {
    printf("fork1 pid=%d ppid=%d pgid=%d\n", getpid(), getppid(),
           getpgid(getpid()));
    sleep(5);
    return 1;
  }
  waitid();
  return 0;
}
