#include <stdio.h>
#include <stdlib.h>

int main(void)
{
       int *pMMem; // malloc用
       int *pCMem; // calloc用
       pMMem = (int *)malloc(sizeof(int) * 3);
       pCMem = (int *)calloc(3, sizeof(int));
       //確保領域の初期値表示
       printf("malloc [0]:0x%08x, [1]:0x%08x, [2]:0x%08x\n", pMMem[0], pMMem[1], pMMem[2]);
       printf("calloc [0]:0x%08x, [1]:0x%08x, [2]:0x%08x\n", pCMem[0], pCMem[1], pCMem[2]);
       free(pMMem);
       free(pCMem);
       return 0;
}
