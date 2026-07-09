#include <stdio.h>
#include <stdlib.h>

// Array as ADT
struct Array
{
    int *a;
    int total_size;
    int used_size;
};

// Array creation function
void createArray(struct Array *arr, int u_size, int t_size)
{
    arr->used_size = u_size;
    arr->total_size = t_size;
    arr->a = (int *)malloc(arr->total_size * sizeof(int));
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter element %d\n", i);
        scanf("%d", &arr->a[i]);
    }
}

// Array display function Time complexity O(n)
void displayArray(struct Array *arr)
{
    printf("Displaying array\n");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", arr->a[i]);
    }
}

// Insert element at index function Time complexity O(n)
int insertElementatI(struct Array *arr, int index, int element)
{

    if (index < 0 && index >= arr->total_size)
    {
        printf("Invalid index\n");
        return -1;
    }

    for (int i = arr->used_size - 1; i >= index; i--)
    {
        arr->a[i + 1] = arr->a[i];
    }
    arr->a[index] = element;
    arr->used_size++;

    return 1;
}

// Delete element at index function Time complexity O(n)
int deleteElementatI(struct Array *arr, int index)
{
    if (index < 0 && index >= arr->used_size)
    {
        printf("Invalid index\n");
        return -1;
    }

    for (int i = index; i < arr->used_size - 1; i++)
    {
        arr->a[i] = arr->a[i + 1];
    }
    arr->used_size--;
    return 1;
}

// Linear search function Time complexity O(n)
int linearSearch(struct Array *arr, int element)
{

    for (int i = 0; i < arr->used_size; i++)
    {
        if (arr->a[i] == element)
        {
            return i;
        }
    }

    return -1;
}

// Binary search function - (Works only on sorted array) Time complexity O(logn)
int binarySearch(struct Array *arr, int element)
{

    int low = 0;
    int high = arr->used_size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr->a[mid] == element)
        {
            return mid;
        }
        else if (arr->a[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr;

    createArray(&arr, 5, 10);
    displayArray(&arr);

    // Insert element at index function call
    int success = insertElementatI(&arr, 2, 45);

    if (success == 1)
    {
        printf("\nElement inserted successfully\n");
        displayArray(&arr);
    }
    else
    {
        printf("\nElement insertion failed\n");
    }

    // Delete element at index function call
    int deletionSuccess = deleteElementatI(&arr, 3);

    if (deletionSuccess == 1)
    {
        printf("\nElement deleted successfully\n");
        displayArray(&arr);
    }
    else
    {
        printf("\nElement deletion failed\n");
    }

    int searchElement = 45;

    // Linear search function call
    int searchIndex = linearSearch(&arr, searchElement);

    if (searchIndex != -1)
    {
        printf("\nElement %d found at index %d\n", searchElement, searchIndex);
    }
    else
    {
        printf("\nElement %d not found in the array\n", searchElement);
    }

    // Binary search works only on sorted array
    searchIndex = binarySearch(&arr, searchElement);

    if (searchIndex != -1)
    {
        printf("\nElement %d found at index %d\n", searchElement, searchIndex);
    }
    else
    {
        printf("\nElement %d not found in the array\n", searchElement);
    }

    return 0;
}