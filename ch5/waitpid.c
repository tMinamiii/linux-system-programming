#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

void waitprocess(pid_t pid) {
  pid_t wpid;
  int status;
  // wpid = waitpid(-1, &status, 0);
  // wpid = wait3(&status, 0, NULL);

  wpid = waitpid(pid, &status, 0);
  wpid = wait4(pid, &status, 0, NULL);

  if (pid == -1) {
    perror("waitpid");
  } else {
    if (WIFEXITED(status)) {
      printf("Normal termination with exit pid=%d status=%d\n", wpid, WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("Killed by signal=%d%s\n", WTERMSIG(status),
             WCOREDUMP(status) ? " (dumped core)" : "");
    }
  }
}

int main() {
  pid_t pid1, pid2;
  pid1 = fork();
  if (!pid1) {
    printf("fork1 pid = %d pgid = %d\n", getpid(), getpgid(getpid()));
    sleep(5);
    return 1;
  } else {
    pid2 = fork();
    if (!pid2) {
      printf("fork2 pid = %d pgid = %d\n", getpid(), getpgid(getpid()));
      sleep(2);
      return 1;
    }
  }

  waitprocess(pid1);
  waitprocess(pid2);
}
