#include <stdio.h>
#include <unistd.h>

int main()
{
  printf("The current break point is %p\n", sbrk(0));
  printf("Increment 1 break point is %p\n", sbrk(1));
  printf("The current break point is %p\n", sbrk(0));
  printf("Increment 1 break point is %p\n", sbrk(1));
  printf("The current break point is %p\n", sbrk(0));
}
