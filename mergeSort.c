#include <stdio.h>

// Function to display array
void displayArray(int *a, int size)
{
    printf("Printing array elements: |");

    for (int i = 0; i < size; i++)
    {
        printf(" %d |", a[i]);
    }

    printf("\n");
}

// Merge algorithm that takes two different part of arrays and reorders them such that we get both parts of the array as sorted
void merge(int *A, int mid, int low, int high){

    int i,j,k,B[100];

    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }else{
            B[k]=A[j];
            j++;
            k++;
        }
    }

    while (i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }

    while(j<=high){
        B[k]=A[j];
        j++;
        k++;
    }

    for(int i=low;i<=high;i++){
        A[i]=B[i];
    }
    
}

// Recursive merge sort Divides array into two equal parts again and again until the divided array size is 1 
// After dividing into smallest part the parts are merged again depending on the order
void mergeSort(int *A, int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(A,low,mid);
        mergeSort(A,mid+1,high);
        merge(A,mid,low,high);
    }
}

int main()
{
    int arr[5] = {12, 54, 74, 86, 9};
    int size = sizeof(arr) / sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Printing array after sorting:\n");
    displayArray(arr, size);

    return 0;
}