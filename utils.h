#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void displayArray(void* array, int size, int type); 
/*
* Type == 1 -> int
* Type == 2 -> float
* Type == 3 -> char 
* Type == 4 -> long
*/

void println();

void updateRandomSeed();

int RandomizedInt(int a, int b);

void printArraySize(void* array);