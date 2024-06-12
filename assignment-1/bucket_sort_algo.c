#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

typedef struct Linked_list
{
    float data;
    struct Linked_list *next;
    struct Linked_list *prev;
} node;

node *LL_insert(node *list, float d)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->data = d;

    if (list == NULL)
        list = new_node;
    else
    {
        node *temp = list;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }

    return list;
}

void showLL(node *list)
{
    node *temp = list;

    while (temp != NULL)
    {
        printf("%0.2f->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node *delete_start(node *list, float *d)
{
    node *temp = list;
    list = list->next;

    if (list != NULL && list->prev != NULL)
        list->prev = NULL;

    *d = temp->data;
    free(temp);

    return list;
}

void swap(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}

node *insertion_sort(node *list, int *count)
{
    if (list != NULL)
    {
        node *ahead = list->next;

        while (ahead != NULL)
        {
            node *rev = ahead;

            while (rev->prev != NULL && rev->prev->data > rev->data)
            {
                swap(&(rev->data), &(rev->prev->data));
                rev = rev->prev;
                (*count)++;
            }
            ahead = ahead->next;
            (*count)++;
        }

        return list;
    }
    return NULL;
}

void bucket_sort(float *arr, int n, int *count)
{
    node *bins[n];

    for (int i = 0; i < n; i++)
        bins[i] = NULL;

    int pos = 0;

    for (int i = 0; i < n; i++)
    {
        pos = floor(n * arr[i]);
        bins[pos] = LL_insert(bins[pos], arr[i]);
    }

    for (int i = 0; i < n; i++)
        bins[i] = insertion_sort(bins[i], count);

    pos = 0;
    float temp;

    for (int i = 0; i < n; i++)
    {
        while (bins[i] != NULL)
        {
            bins[i] = delete_start(bins[i], &temp);
            arr[pos] = temp;
            pos++;
        }
    }
}

int is_array_sorted(float *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
        if (arr[i] > arr[i + 1])
            return 0;

    return 1;
}

void text_to_arr(float *arr, int n)
{

    FILE *fin = fopen("normalized_uniform_distribution.txt", "r"); // in write mode
    char a[6];
    fscanf(fin, "%s\n", a);
    float temp = 0;
    for (int i = 0; i < n; i++)
    {
        int skip_line = rand() % 10;

        for (int j = 0; j < skip_line; j++)
            fscanf(fin, "%f\n", &temp);

        fscanf(fin, "%f\n", &temp);
        arr[i] = temp;
    }

    fclose(fin);
}

void main()
{
    srand(time(0));

    int max_p = 13; // the range limit of p is 0 - (max_p)
    int iter_num = 2000;

    FILE *fout;
    fout = fopen("bucket_uniform_obs.csv", "w");

    fprintf(fout, "BucketSort file \n");
    fprintf (fout, "\n");
    fprintf(fout, "num_elements, avg_comparison, avg_time \n");
    fprintf(fout, "number of iterations for each problem set size is %d\n", iter_num);

    int n = 2;                      // because it'll be power of 2 ;
    for (int p = 0; p < 8; p++) // p is the exponent of the array/problem set size
    {
        long sum_count = 0;
        float sum_time = 0;

        for (int j = 0; j < iter_num; j++)
        {
            float a[n];

            text_to_arr(a, n);

            for (int i = 0; i < n; i++)
                a[i] /= 100;

            // for (int i = 0; i < n; i++)
            //     printf("%0.2f,", a[i]);
            // printf("\n");

            int count = 0;

            float start_time = clock();
            bucket_sort(a, n, &count);
            float end_time = clock();

            sum_count += count;

            float time_taken = (end_time - start_time) * 1000 / CLOCKS_PER_SEC;
            sum_time += time_taken;

            // for (int i = 0; i < n; i++)
            //     printf("%d ", a[i]);
            // printf("\n\n");

            if (is_array_sorted(a, sizeof(a) / sizeof(int)) == 1)
                // printf("Num = %d Run %d: %d comparison, %0.4f ms\n", n, i + 1, count, time_taken);
                printf("prblm set size 2^(%d) = %d , Run %d: %d comparison, %0.4f ms\n", p, n, j + 1, count, time_taken);

            else
            {
                printf("Array Not Sorted\n");
                break;
            }
        }

        float avg_time = sum_time / iter_num;
        long avg_count = sum_count / iter_num;
        printf("avg time taken for prblm size 2^(%d) is %0.4lf \n", p, avg_time);
        fprintf(fout, "problem set size 2^(%d) = %d elements ,avg count --> %ld ,avg. time -->%0.4f\n", p, n, avg_count, avg_time);
        n *= 2;
    }

    fclose(fout);
}