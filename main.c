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
    
    piece temp[nbPieces];
    tab = temp;
}


int main()
{
    printf("Hello, World\n");

    generateTab(4, 1);
    displayArray(tab, nbPieces, 1);
    printf("%d", nbPieces);
    println();
    return 0;
}