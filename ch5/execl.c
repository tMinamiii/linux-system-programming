#include <stdio.h>
#include <unistd.h>

int main() {
  int ret;
  printf("pid=%d\n", getpid());
  sleep(10);
  ret = execl("/usr/bin/vim", "vim", "hooks.txt", NULL);
  if (ret == -1) {
    perror("execl");
  }
}
