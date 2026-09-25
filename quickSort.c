#include <stdio.h>

// Function to display array elements
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

/* Partition function that sorts array around pivot such that
        val<=pivot | pivot | val>pivot
   and returns the index of pivot*/
int partition(int *a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp = 0;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

// Quick sort function Recursive calls
int quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int A[] = {12, 54, 74, 86, 9};
    int n = sizeof(A) / sizeof(int);
    printf("Printing array before sorting....\n");
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printf("Printing array after sorting....\n");
    printArray(A, n);
    return 0;
}
