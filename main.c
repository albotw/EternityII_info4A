#include "main.h"
#include "utils.h"

void generateTab(int size, int mode)
{
    switch (size)
    {
        case 4:
            nbPieces = 16;
            break;

        case 5:
            nbPieces = 25;
            break;
        
        case 6:
            nbPieces = 36;
            break;
        
        case 7: 
            nbPieces = 56;
            break;
    }
    
    cote = size;

    tab = malloc(nbPieces * sizeof(piece));

    for (int i = 0; i < nbPieces; i++)
    {
        piece p = {'A', 'B', 'C', 'D'};
        tab[i] = p;
    }
}



piece getPieceAt(int x, int y)
{
    return tab[(x + (cote * y))];
}

void setPieceAt(int x, int y, piece p)
{
    tab[(x + (cote * y))] = p;
}

void swap(int x1, int y1, int x2, int y2)
{
    piece temp = getPieceAt(x1, y1);
    piece temp2 = getPieceAt(x2, y2);
    setPieceAt(x1, y1, temp2);
    setPieceAt(x2, y2, temp);    
}

void rotate(int x, int y)
{
    piece origine = getPieceAt(x, y);
    piece new = {origine.W, origine.N, origine.E, origine.S};
    setPieceAt(x, y, new);
}

char* formatChar(char c)
{
    char* S = malloc(25 * sizeof(char));
    switch (c)
    {
        case 'A':
        {
            S = "\033[48;5;9m\033[38;5;0mA\033[0m";
            break;
        }
        case 'B':
        {
            S = "\033[48;5;13m\033[38;5;0mB\033[0m";
            break;
        }
        case 'C':
        {
            S = "\033[48;5;11m\033[38;5;0mC\033[0m";
            break;
        }
        case 'D':
        {
            S = "\033[48;5;14m\033[38;5;0mD\033[0m";
            break;
        }
    }

    return S;
}

void draw()
{
    for (int i = 0; i < cote; i++)
    {
        char top[(30*cote)];
        char mid[(60*cote)];
        char bot[(30*cote)];

        top[0] = '\0';
        mid[0] = '\0';
        bot[0] = '\0';

        char* c = NULL;
        for (int j = 0; j < cote; j++)
        {
            piece p = getPieceAt(j, i);

            c = formatChar(p.N);
            sprintf(top + strlen(top), "  %s   ", c);

            c = formatChar(p.W);
            sprintf(mid + strlen(mid), "%s # ", c);

            c = formatChar(p.E);
            sprintf(mid + strlen(mid), "%s ", c);

            c = formatChar(p.S);
            sprintf(bot + strlen(bot), "  %s   ", c);
        }
        
        printf("%s\n", top);
        printf("%s\n", mid);
        printf("%s\n", bot);
    }
}

int main()
{
    printf("\033[48;5;11m\033[38;5;0mHello\033[0m\n");

    generateTab(7, 1);
    printf("%c", tab[0].N);
    println();
    printf("%d", nbPieces);
    println();
    draw(tab);

    rotate(0, 0);

    rotate(1, 1);
    rotate(1, 1);

    swap(1, 1, 3, 3);
    println();
    draw(tab);
    free(tab);
    return 0;
}