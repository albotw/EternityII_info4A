#include "main.h"
#include "utils.h"

int checkConflicts()
{
    int conflits = 0;
    for(int i = 0; i < cote; i++)
    {
        for (int j = 0; j < cote; j++)
        {
            piece p = getPieceAt(j, i);

            if (getPieceAt(j - 1, i).E != p.W)
            {
                conflits++;
            }
            if (getPieceAt(j, i - 1).S != p.N)
            {
                conflits++;
            } 
            if (getPieceAt(j + 1, i).W != p.E){
                conflits++;
            }
            if (getPieceAt(j, i + 1).N != p.S)
            {
                conflits++;
            }
        }
    }

    return conflits / 2;
}

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

    tab = (piece* )malloc(nbPieces * sizeof(piece));

    for (int i = 0; i < nbPieces; i++)
    {
        piece p = {'A', 'B', 'C', 'D'};
        tab[i] = p;
    }
}



piece getPieceAt(int x, int y)
{
    if (x < 0)
    {
        x = cote -1;
    }
    else if (x > cote -1)
    {
        x = 0;
    }

    if (y < 0)
    {
        y = cote - 1;
    } 
    else if (x > cote - 1)
    {
        y = 0;
    }
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

void readCommand()
{
    printf("Coordonnées possibles: x ~= [%c,%c] | y ~= [%d,%d]\n",'A', 'A' + cote -1, 0, cote - 1);
    printf("usage: XY ~> rotation | X1Y1X2Y2 ~> echange\n");

    char* command = calloc(5, sizeof(char));
    scanf("%s", command);

    if (strlen(command) == 2)
    {
        int x = 'A' - command[0];
        int y = '0' - command[1];
        printf("Rotation: %d|%d\n", x, y);
        if (0 <= x && x <= cote && 0 <= y && y <= cote)
        {
            rotate(x, y);
        }
        else
        {
            printf("Erreur: coordonnées invalides\n");
        }
    }
    else if(*(command + 4) == '\0')
    {
        int x1 = 'A' - command[0];
        int y1 = (char)command[1] - '0';
        int x2 = 'A' - command[2];
        int y2 = (char)command[3] - '0';
        printf("Swap: %d|%d ~> %d|%d\n", x1, x2, y1, y2);
        if (0 <= x1 && x1 <= cote && 0 <= y1 && y1 <= cote && 0 <= x2 && x2 <= cote && 0 <= y2 && y2 <= cote)
        {
            swap(x1, y1, x2, y2);
        }
        else
        {
            printf("Erreur: coordonnées invalides \n");
        }
    }
    else
    {
        printf("Erreur: commande non reconnue \n");
    }
    free(command);
}
int main()
{
    int restart;

    do
    {
        restart = 0;
        int taille = choixTailleTableau();
        generateTab(taille + 3, 1);
        
        int victory;
        do{
            draw();
            readCommand();
            victory = checkConflicts();
            printf("Il y a %d conflits restants\n", victory);
            println();
        }while(victory != 0);
        
        
        restart = rejouer();
        if (restart)
        {
            free(tab);
            tab = NULL;
        }
    }
    while(restart);
    return 0;
}

int choixTailleTableau()
{
    int y;
    int loop = 0;
    do
    {
        loop = 0;
        printf("Quelle taille de tableau allez vous prendre ?\n");
        printf("1: 4x4\n");
        printf("2: 5x5\n");
        printf("3: 6x6\n");
        printf("4: 7x7\n");
        scanf("%d", &y);

        if (1 > y || y > 4)
        {
            loop = 1;
            printf("Erreur: option invalide\n");
        }
    } while (loop);
    println();
    return y;
}

int rejouer()
{
    int temp;
    printf("Rejouer ?\n");
    printf("1: Oui\n");
    printf("2: Non\n");
    scanf("%d", &temp);

    if (temp == 2)
    {
        temp = 0;
    }
    return temp;
}