#include "utils.h"

void println()
{
    printf("\n");
}

void displayArray(void* array, int size, int type)
{
    switch(type)
    {
        case 1:
            int* ptr = (int *)array;
            for (int i = 0; i < size; i++)
            {
                printf("%d ", *ptr);
                ptr++;
            }
            break;
        
        case 2:
            float* ptr = (float *)array;
            for (int i = 0; i < size; i++)
            {
                printf("%f", *ptr);
                ptr++;
            }
            break;

        case 3:
            char* ptr = (char *)array;
            for (int i = 0; i < size; i++)
            {
                printf("%c", *ptr);
                ptr++;
            }
            break;

        case 4:
            long* ptr = (long *)array;
            for (int i = 0; i < size; i++)
            {
                printf("%l", *ptr);
                ptr++;
            }
            break;
    }
    println();
}