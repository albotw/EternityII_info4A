#include <stdio.h>
#include <stdlib.h>

#define maxSize 50000   //? Taille max en Octets
#define maxBlocks 5000  //? Nombre max de blocs allouables.

typedef struct{
    void* adr;
    unsigned size;
}block;

unsigned dmSize;    //? taille actuelle en octets du tas
unsigned nbBlocks;  //? nb de blocs instanciés dans le tas
block** blocks;   //? Tableau référençant tous les blocs mémoire crées.

int find(int mode, void* adr);
//? mode == 0 ~> find first empty
//? mode == 1 ~> find from address

void initDMM();

void* _malloc(unsigned size);

void _free(void* adr);
