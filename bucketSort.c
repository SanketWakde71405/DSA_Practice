// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <stdlib.h>

// Function to display array
void displayArray(float *a, int size)
{

    for (int i = 0; i < size; i++)
    {
        printf(" %.3f |", a[i]);
    }

    printf("\n");
}

void insertionSort(float *b, int n)
{
    float key = 0.0;
    int j = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        j = i - 1;
        key = b[i];
        while (j >= 0 && b[j] > key)
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

void bucketSort(float *a, int n)
{
    float **buckets = (float **)malloc(n * sizeof(float *));
    int *bucketSize = (int *)calloc(n, sizeof(int));

    // Allocate the size for each bucket;
    for (int i = 0; i < n; i++)
    {
        buckets[i] = (float *)malloc(n * sizeof(float));
    }

    // Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = (int)(a[i] * n);
        buckets[index][bucketSize[index]] = a[i];
        bucketSize[index]++;
    }

    // Sorting each bucket using insertion sort
    for (int i = 0; i < n; i++)
    {
        insertionSort(buckets[i], bucketSize[i]);
    }

    // Combine buckets back into original array
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucketSize[i]; j++)
        {
            a[index] = buckets[i][j];
            index++;
        }
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSize);
}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Printing elements before sorting...\n");
    displayArray(arr, n);
    bucketSort(arr, n);
    printf("Printing elements after sorting...\n");
    displayArray(arr, n);

    return 0;
}