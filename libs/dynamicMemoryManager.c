#include "dynamicMemoryManager.h"

int find(int mode, void* adr)
{
    int output = -1;
    if (mode == 0)
    {
        do
        {
            output++;
        }while(blocks[output] != NULL && output < maxBlocks);
    }
    else if (mode == 1)
    {
        int found = 0;
        for(int i = 0; i < nbBlocks; i++)
        {
            block* tmp = blocks[i];
            void* ptr = tmp->adr;
            printf("%p | %p\n", &(*ptr), &(*adr));
            if (found == 0 && ptr == adr)
            {
                output = i;
                found = 1;
            }
        }
    }
    return output;
}

void* _malloc(unsigned size)
{
    if (dmSize + size <= maxSize && nbBlocks + 1 <= maxBlocks)
    {
        dmSize = dmSize + size;
        nbBlocks++;

        block b = {malloc(size), size};

        int position = find(0, NULL);
        blocks[position] = &b;
        
        printf("Allocated %u bytes @ %p\n", size, b.adr);
        return b.adr;
    }
    else
    {
        printf("Error: dynamic memory saturated");
        return NULL;
    }
}

void _free(void* adr)
{
    
    int position = find(1, adr);
    printf("%d\n", position);
    block* b = blocks[position];
    dmSize = dmSize - b->size;
    printf("%d\n", dmSize);
    free(b->adr);
    
    blocks[position] = NULL;
}


void initDMM()
{
    blocks = calloc(maxBlocks, sizeof(block));
}
