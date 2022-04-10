#include <alloca.h>
#include <stdio.h>

int open_sysconf(const char *file, int flags, int mode) {
  const char *etc = SYSCONF_DIR;
  char *name;
  size_t size = strlen(etc) + strlen(file) + 1;
  name = alloca(size);
  strcpy(name, etc);
  strcat(name, file);

  return open(name, flags, mode);
}
int main() {}
