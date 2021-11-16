#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void waitprocess() {
  pid_t pid;
  int status;
  pid = waitpid(0, &status, 0);
  if (pid == -1) {
    perror("waitpid");
  } else {
    printf("pid=%d\n", pid);

    if (WIFEXITED(status)) {
      printf("Normal termination with exit status=%d\n", WEXITSTATUS(status));
    }
    if (WIFSIGNALED(status)) {
      printf("Killed by signal=%d%s\n", WTERMSIG(status),
             WCOREDUMP(status) ? " (dumped core)" : "");
    }
  }
}

int main() {
  if (!fork()) {
    printf("fork1 = %d gpid = %d\n", getpid(), getpgid(getpid()));
    return 1;
  }
  if (!fork()) {
    printf("fork2 = %d gipd = %d\n", getpid(), getpgid(getpid()));
    return 1;
  }

  waitprocess();
  sleep(1);
  waitprocess();
}
