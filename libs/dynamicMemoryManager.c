#include "dynamicMemoryManager.h"

int find(int mode, void* adr)
{
    int output = -1;
    if (mode == 0)
    {
        do
        {
            output++;
        }while(blocks[output] != NULL);
    }
    else if (mode == 1)
    {
        int found = 0;
        for(int i = 0; i < nbBlocks; i++)
        {
            void** ptr = blocks[i]->adr;
            printf("%p | %p\n", &ptr, adr);
            if (found == 0 && blocks[i]->adr == adr)
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
    if (dmSize + size <= maxBlocks)
    {
        dmSize = dmSize + size;
        nbBlocks++;

        block b = {size, malloc(size)};

        int position = find(0, NULL);
        blocks[position] = &b;
        
        printf("%p\n", b.adr);
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
    printf("test past position, %d \n", position);
    block* b = blocks[position];
    printf("test post recup");
    printf("%ul", (*b).size);
    dmSize = dmSize - (*b).size;
    
    free((*b).adr);

    //blocks[position] = NULL;
}

