#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int status;

  pid_t pid;
  if (!fork()) {
    // 子プロセスの処理
    abort();
    // return 1;
  }

  pid = wait(&status);
  if (pid == -1)
    perror("wait");

  printf("pid=%d\n", pid);

  if (WIFEXITED(status)) {
    printf("Normal termination with exit status=%d\n", WEXITSTATUS(status));
  }

  if (WIFSIGNALED(status)) {
    printf("Killed by signal=%d%s\n", WTERMSIG(status),
           WCOREDUMP(status) ? " (dumpled core)" : "");
  }

  // WIFSTOPPED、WIFCONTINUED
  // は子プロセスがptrace()経由で実行されており、中断、再開された場合に
  // それぞれ真を返します。このマクロを条件として使用するのは通常はデバッガだけでしょう
  if (WIFSTOPPED(status)) {
    printf("Stopped by signal=%d\n", WSTOPSIG(status));
  }

  if (WIFCONTINUED(status)) {
    printf("Continued\n");
  }

  return 0;
}
