#include <stdio.h>
#include <stdlib.h>

#define maxBlocks 20000

typedef struct{
    int size;
    void* adr;
}block;

unsigned dmSize;
unsigned nbBlocks;
block* blocks[maxBlocks];

int find(int mode, void* adr);
//? mode == 0 ~> find first empty
//? mode == 1 ~> find from address

void* _malloc(unsigned size);

void _free(void* adr);
