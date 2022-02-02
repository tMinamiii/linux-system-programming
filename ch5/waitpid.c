#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void waitprocess(pid_t pid) {
  pid_t wpid;
  int status;
  // wpid = waitpid(-1, &status, 0);
  // wpid = wait3(&status, 0, NULL);
  // sleep(6);
  wpid = waitpid(pid, &status, 0);
  // wpid = wait4(pid, &status, 0, NULL);
  if (wpid == 0) {
    printf("child process alived\n");
    return;
  }
  if (pid == -1) {
    perror("waitpid");
  } else {
    if (WIFEXITED(status)) {
      printf("Normal termination with exit pid=%d wpid=%d status=%d\n",
             getpid(), wpid, WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("Killed by signal=%d%s\n", WTERMSIG(status),
             WCOREDUMP(status) ? " (dumped core)" : "");
    }
  }
}

int main() {
  pid_t pid1, pid2, pid3;
  pid1 = fork();
  if (!pid1) {
    printf("fork1 pid=%d ppid=%d pgid=%d\n", getpid(), getppid(),
           getpgid(getpid()));
    pid3 = fork();
    if (!pid3) {
      printf("fork3 pid=%d ppid=%d pgid=%d\n", getpid(), getppid(),
             getpgid(getpid()));
    }
    sleep(5);
    return 1;
  } else {
    pid2 = fork();
    if (!pid2) {
      printf("fork2 pid=%d ppid=%d pgid=%d\n", getpid(), getppid(),
             getpgid(getpid()));
      sleep(2);
      return 1;
    }
  }

  waitprocess(pid1);
  waitprocess(pid2);
  waitprocess(pid3);
  return 0;
}
