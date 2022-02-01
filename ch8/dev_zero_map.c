#include <fcntl.h>
#include <malloc.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  void *p;
  int fd;

  fd = open("/dev/zero", O_RDWR);
  if (fd < 0) {
    perror("open");
    return -1;
  }

  p = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (p == MAP_FAILED) {
    perror("mmap");
    if (close(fd)) {
      perror("close");
    }
  }

  if (close(fd)) {
    perror("close");
  }

  // printf("/dev/zero mmap %lu\n", malloc_usable_size(p));
}
