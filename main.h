#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int x;
    int y;
}position;

typedef struct{
    char N;
    char S;
    char W;
    char E;

    position p;
}piece;

piece* tab;
int cote;   //taille du côté
int nbPieces;

void generateTab(int size, int mode); // mode 1 = mode simple, mode 2 = mode complexe

void rotate(int posX, int posY);

void swap(int posX1,int posY1, int posX2, int posY2);

piece getPieceAt(int x, int y);

void setPieceAt(int x, int y, piece p);

void draw(piece tab[]);

void checkConflicts(piece tab[]);

void checkVictory(piece tab[]);

void readCommand();

char* formatChar(char c);

void AI();


