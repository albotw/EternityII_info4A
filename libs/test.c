#include <stdio.h>
#include <stdlib.h>

#include "dynamicMemoryManager.h"

int main()
{
    for(int i = 0; i < 1000000; i++)
    {
        void* ptr = _malloc(10000*sizeof(char));
        _free(ptr);
        
    }
    printf("test\n");
    return 0;
}