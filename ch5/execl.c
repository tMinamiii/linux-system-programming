#include <stdio.h>
#include <unistd.h>

int main() {
  int ret;
  ret = execl("/usr/local/bin/vim", "vim", "./hooks.txt", NULL);
  if (ret == -1) {
    perror("execl");
  }
}
