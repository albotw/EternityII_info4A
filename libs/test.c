#include <stdio.h>
#include <stdlib.h>

#include "dynamicMemoryManager.h"

int main()
{
    initDMM();
    for(int i = 0; i < 100; i++)
    {
        printf("test pre malloc\n");
        void* ptr = _malloc(10000*sizeof(char));
        printf("main ptr value= %p\n", ptr);
        _free(ptr);
        printf("test post free");
    }
    printf("test\n");
    return 0;
}