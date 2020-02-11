#include <stdio.h>
#include <stdlib.h>

#define maxSize 50000
#define maxBlocks 5000

typedef struct{
    void* adr;
    int size;
}block;

unsigned dmSize;
unsigned nbBlocks;
block* blocks[maxBlocks];

int find(int mode, void* adr);
//? mode == 0 ~> find first empty
//? mode == 1 ~> find from address

void* _malloc(unsigned size);

void _free(void* adr);
