// CODE FOR RANDOM DATA GENERATOR WITH PROBLEM SET SIZE IN INCREASING 2'S POWER

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for srand() and rand() function
#include <math.h> // for pow function

void main()
{

    srand(time(0)); // srand() seeds the random number generator , generates random number based on current time

    FILE *fout;
    //fout = fopen("random_dataset_file.txt", "w");  // for normal text files
    fout = fopen("random_dataset_file.csv", "w");  // for csv(comma seperated values) files


    for (int p = 0; p < 7; p++) // varying the problem set size with 2's multiple
    {
        for (int j = 0; j < 10; j++) // each problem set of a specific size will be generated 100 times
        {
            int n = pow(2, p); // n is the size of the array/problem set in 2's power
            int a[n];

            for (int i = 0; i < n; i++)
            {
                a[i] = rand() % 100;         // generating random number between 0-(100-1)
                printf("%d ", a[i]);         // for printing in the terminal/output
                fprintf(fout, "%d\t", a[i]); // for printing in the file
            }
            printf("\n");
            fprintf(fout, "\n");
        }
        printf("\n");
        fprintf(fout, "\n");
    }
    fclose(fout);
}