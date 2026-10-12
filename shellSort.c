#include <stdio.h>
#include <stdlib.h>

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

void shellSort(int *A, int size){

    int key = 0;
    int j = 0;
    for(int gap=size/2;gap>0;gap/=2){
        for(int i=gap;i<size;i++){
            key=A[i];
            j=i;
            while(j>=gap && A[j-gap]>key){
                A[j]=A[j-gap];
                j-=gap;
            }

            A[j]=key;
           
        }
    }
}


int main()
{

    int arr[] = {12, 11, 13, 5, 6, 7, 5};
    int size = sizeof(arr) / sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr, size);

    shellSort(arr, size);

    printf("Printing array after sorting:\n");
    displayArray(arr, size);



    return 0;
}