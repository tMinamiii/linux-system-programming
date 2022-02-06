#include <malloc.h>

int main()
{
  // int ret;
  // ret = mallopt(M_MMAP_THRESHOLD, 64);
  // if (!ret)
  //   fprintf(stderr, "mallopt failed!\n");

  size_t len = 100;
  size_t size;
  char *buf;
  buf = malloc(len);
  if (!buf)
  {
    perror("malloc");
    return -1;
  }
  size = malloc_usable_size(buf);

  printf("malloc usable size %lu\n", size);
}
