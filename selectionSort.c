#include <stdio.h>

// Function to display array elements
void displayArray(int *a, int size)
{
    printf("Printing array elements: |");

    for (int i = 0; i < size; i++)
    {
        printf(" %d |", a[i]);
    }

    printf("\n");
}

// Selection sort algorithm
void selectionSort(int *arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[5] = {12, 54, 74, 86, 9};
    int size = sizeof(arr) / sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr, size);
    selectionSort(arr, size);
    printf("Printing array after sorting:\n");
    displayArray(arr, size);

    return 0;
}