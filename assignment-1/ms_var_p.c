#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void merge(int *arr, int initial, int mid, int final)
{
    int size1 = mid - initial + 1;
    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[initial + i];
    }

    int size2 = final - mid;
    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int arr1_pos = 0;
    int arr2_pos = 0;
    int arr_pos = initial;
    int count = 0;

    while (arr1_pos < size1 && arr2_pos < size2)
    {
        if (arr1[arr1_pos] < arr2[arr2_pos])
        {
            arr[arr_pos] = arr1[arr1_pos];
            count++;
            // return count;
            arr1_pos++;
            arr_pos++;
        }
        else
        {
            arr[arr_pos] = arr2[arr2_pos];
            count++;
            // return count;
            arr2_pos++;
            arr_pos++;
        }
    }
    // return count;

    while (arr1_pos < size1)
    {
        arr[arr_pos] = arr1[arr1_pos];
        arr1_pos++;
        arr_pos++;
    }

    while (arr2_pos < size2)
    {
        arr[arr_pos] = arr2[arr2_pos];
        arr2_pos++;
        arr_pos++;
    }

    // printf(" total swap operation is %d ", count);
}

// sorts array of int type in ascending order, put initial as 0, and final as (size -1)

void merge_sort(int *arr, int initial, int final)
{
    if (initial < final)
    {
        int mid = (initial + final) / 2;
        merge_sort(arr, initial, mid);
        merge_sort(arr, mid + 1, final);
        merge(arr, initial, mid, final);
    }
}

// assuming 1 is true, 0 is false
int is_array_sorted(int *arr, int length)
{
    for (int i = 0; i < (length - 1); i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void main()
{

    srand(time(0));    // srand() seeds the random number generator , generates random number based on current time
    int iter_num = 10; // number of iterations for each problem set ...
    printf("total number of iteratons/problem set size is -->  %d ", iter_num);
    printf("\n");

    double start_time = clock(); // clock() fn used to measure the time taken by a program to execute...

    FILE *fout;
    fout = fopen("merge_sort output file.txt", "w");
    // fout = fopen("merge_sort output file.csv", "w");

    for (int p = 0; p < 7; p++)

    {
        double start_time = clock(); // clock() fn used to measure the time taken by a program to execute...

        for (int j = 0; j < iter_num; j++) // j is the iteration variable that goes from 0 to (iter_num -1)
        {
            int n = pow(2, p);
            int a[n];
            for (int i = 0; i < n; i++)
                a[i] = rand() % 100;

            printf("run -->  %d for problem size 2^(%d)", j + 1, p);
            printf("\n");

            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
                // printf("\n");

                fprintf(fout, "%d\t", a[i]);
                // fprintf(fout, "\n");
            }
            printf("\n\n");
            printf("sorted array is -->");
            printf("\n");

            fprintf(fout, "\n");
            fprintf(fout, "sorted array is --> ");
            fprintf(fout, "\n");

            int count = 0;

            double start_time = clock(); // clock() fn used to measure the time taken by a program to execute...

            merge_sort(a, 0, n - 1);

            for (int i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
                fprintf(fout, "%d\t", a[i]);

                // printf("total swap operation is %d", count);
                // fprintf(fout, "\n");
            }
            printf("\n");
            fprintf(fout, "\n");

            double end_time = clock();

            if (is_array_sorted(a, sizeof(a) / sizeof(int)) == 1)
            {
                printf("Run %d: (above) execution time %0.6f ms  for problem set size (2)^%d \n", j + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC, p);
                // printf("for problem set size (2)^%d \n", p);
                printf("\n");

                // when j=0 , the run should show 1st run and so on ...
                fprintf(fout, "Run %d: (above) execution time %0.6f ms for problem set size (2)^%d \n", j + 1, (end_time - start_time) * 1000 / CLOCKS_PER_SEC, p);
                // fprintf(fout, "for problem set size (2)^%d \n", p);
                fprintf(fout, "\n");
            }
            else
            {
                printf("Error !!! Array Not Sorted \n");
                fprintf(fout, "Error !!! Array Not Sorted \n");

                break;
            }
        }
        double end_time = clock();
    }
    double end_time = clock();
    printf("total exec. time  %0.4f ms \n", (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
    printf("\n");
    printf("avg.total exec. time (for one iteration)  %0.4f ms \n", ((end_time - start_time) * 1000 / CLOCKS_PER_SEC) / iter_num);
    printf("\n\n");

    fprintf(fout, "total exec. time  %0.4f ms \n", (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
    fprintf(fout, "\n");
    fprintf(fout, "avg.total exec. time (for one iteration)  %0.4f ms \n", ((end_time - start_time) * 1000 / CLOCKS_PER_SEC) / iter_num);
    fprintf(fout, "\n\n");

    fprintf(fout, "total exec. time  %0.4f ms \n", (end_time - start_time) * 1000 / CLOCKS_PER_SEC);
    fprintf(fout, "\n");
    fprintf(fout, "avg.total exec. time (for one iteration)  %0.4f ms \n", ((end_time - start_time) * 1000 / CLOCKS_PER_SEC) / iter_num);
    fprintf(fout, "\n\n");
}
