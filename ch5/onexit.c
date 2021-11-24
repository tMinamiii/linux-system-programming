#include <stdio.h>
#include <stdlib.h>

char a[] = "abc";
void out(int status, void *arg) {
  printf("on_exit() succeeded! %s status = %d\n", (char *)arg, status);
}

int main(void) {
  // char *a = "abc";
  if (on_exit(out, a))
    fprintf(stderr, "on_exit() failed! 1 \n");
  // if (on_exit(out, "on exit 2"))
  //   fprintf(stderr, "on_exit() failed! 2 \n");
  // if (on_exit(out, "on exit 3"))
  //   fprintf(stderr, "on_exit() failed! 3 \n");
  return 1;
}
