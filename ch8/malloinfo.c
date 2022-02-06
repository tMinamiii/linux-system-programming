#include <malloc.h>

void print_malloinfo()
{
  struct mallinfo m;
  m = mallinfo();
  printf("size of data segment used by malloc: %d\n", m.arena);
  printf("number of free chunks: %d\n", m.ordblks);
  printf("number of fast bins: %d\n", m.smblks);
  printf("number of anonymous mappings : %d\n", m.hblks);
  printf("size of anonymous mappings: %d\n", m.hblkhd);
  printf("maximum total allocated size: %d\n", m.usmblks);
  printf("size of available fast bins: %d\n", m.fsmblks);
  printf("size of total allocated space: %d\n", m.uordblks);
  printf("size of available chunks: %d\n", m.fordblks);
  printf("size of trimmable space: %d\n", m.keepcost);
  printf("\n");
}

int main()
{
  char *buf;
  size_t len = 128;
  buf = malloc(len);
  print_malloinfo();
  malloc_stats();

  malloc_trim(len);
  print_malloinfo();
  malloc_stats();
}
