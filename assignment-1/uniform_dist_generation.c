#include <stdio.h>
#include <time.h>   //for random seed
#include <stdlib.h> //for rand() and srand() function

const int NO_OF_ELEMENTS = 10e6;  // this amnt of dara will be generated
const int MAX_VALUE = 100; // so the value of the numbers will lie between 0 - (100-1)

void main()
{
    srand(time(0));

    FILE *fout;
    fout = fopen("uniform_distribution.csv", "w");

    // 'w' is the file access mode , Creates an empty file for writing ...

    for (int i = 0; i < NO_OF_ELEMENTS; i++)
    {
        fprintf(fout, "%d\n", rand() % MAX_VALUE);
    }
    fclose(fout);
}