#include<stdio.h>

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

// Insertion Sort Algorithm
void insertionSort(int *a, int size){
    int key=0;
    int j=0;
    for(int i=1;i<=size-1;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;
        
    }
}

int main(){

    int arr[5] = {12, 54, 74, 86, 9};
    int size = sizeof(arr) / sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr, size);
    insertionSort(arr,size);
    printf("Printing array after sorting:\n");
    displayArray(arr, size);

    return 0;
}