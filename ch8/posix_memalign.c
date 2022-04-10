#include <stdio.h>
#include <stdlib.h>

int main() {
  void *buf;
  int ret;

  ret = posix_memalign(&buf, 256, 1024);
  if (ret) {
    fprintf(stderr, "posix_memalign: %d\n", ret);
    return -1;
  }

  free(buf);
}
