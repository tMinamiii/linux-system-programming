#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pMMem; // malloc用
  int *pCMem; // calloc用

  pMMem = (int *)malloc(sizeof(int) * 1024);
  pCMem = (int *)calloc(1024, sizeof(int));

  //確保領域の初期値表示
  printf("malloc [0]:0x%08x, [1]:0x%08x, [2]:0x%08x\n", pMMem[100], pMMem[101],
         pMMem[102]);
  printf("calloc [0]:0x%08x, [1]:0x%08x, [2]:0x%08x\n", pCMem[100], pCMem[101],
         pCMem[102]);

  free(pMMem);
  free(pCMem);

  return 0;
}
