#include <stdio.h>
#include <stdlib.h>

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

// Array display function
void displayArray(struct Array *arr)
{
    printf("Displaying array\n");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", arr->a[i]);
    }
}

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

int main()
{
    struct Array arr;

    createArray(&arr, 5, 10);
    displayArray(&arr);
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

    int deletionSuccess =deleteElementatI(&arr,3);

    if(deletionSuccess==1){
        printf("\nElement deleted successfully\n");
        displayArray(&arr);
    }
    else{
        printf("\nElement deletion failed\n");
    }
    return 0;
}