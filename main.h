#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int x;
    int y;
}pos;

typedef struct{
    char N;
    char S;
    char W;
    char E;

    pos p;
}piece;

piece* tab;
int nbPieces;

void generateTab(int size, int mode); // mode 1 = mode simple, mode 2 = mode complexe

void rotate(int posX, int posY);

void swap(int posX1,int posY1, int posX2, int posY2);

void draw(piece tab[]);

void checkConflicts(piece tab[]);

void checkVictory(piece tab[]);

void readCommand();

void AI();
