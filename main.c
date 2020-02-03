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

    piece temp[nbPieces];
    tab = temp;

    for (int i = 0; i < nbPieces; i++)
    {
        position pos = {0, 0};
        piece p = {'A', 'B', 'C', 'D', pos};
        tab[i] = p;
    }
}

piece getPieceAt(int x, int y)
{
    return tab[(y + cote * x)];
}

void draw(piece tab[])
{
    for (int i = 0; i < 1; i++)
    {
        char top[(5*cote)];
        char mid[(5*cote)];
        char bot[(5*cote)];

        for (int j = 0; j < cote; j++)
        {
            piece p = getPieceAt(i, j);
            sprintf(top + strlen(top), "%c", p.N);
            sprintf(mid + strlen(mid), "%c%c", p.W, p.E);
            sprintf(bot + strlen(bot), "%c", p.S);

            printf("%c", p.N);
            println();
        }
        
        printf("%s", top);
        println();
        printf("%s", mid);
        println();
        printf("%s", bot);
        println();
    }
}

int main()
{
    printf("Hello, World\n");

    generateTab(4, 1);
    printf("%c", tab[0].N);
    println();
    printf("%d", nbPieces);
    println();
    draw(tab);
    return 0;
}