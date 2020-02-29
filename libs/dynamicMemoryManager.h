#include <stdio.h>
#include <stdlib.h>

#define maxSize 50000   //? Taille max en Octets
#define maxBlocks 5000  //? Nombre max de blocs allouables.

typedef struct{
    void* adr;
    int size;
}block;

unsigned dmSize;    //? taille actuelle en Octets de la Pile
unsigned nbBlocks;  //? nb de blocs instanciés dans la pile
block* blocks;   //? Tableau référençant tous les blocs mémoire crées.

int find(int mode, void* adr);
//? mode == 0 ~> find first empty
//? mode == 1 ~> find from address

void initDMM();

void* _malloc(unsigned size);

void _free(void* adr);
