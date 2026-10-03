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

void countSort(int *A, int size){

    int max=0;
    for(int i=0;i<size;i++){
        if(A[i]>max){
            max=A[i];
        }
    }

    int *B=(int*)malloc((max+1)*sizeof(int));

    for(int i=0;i<=max;i++){
        B[i]=0;
    }

    for(int i=0;i<size;i++){
        B[A[i]]++;
    }

    int k=0;
    int i=0;

    while(i<=max){
        if(B[i]>0){
            A[k]=i;
            k++;
            B[i]--;
        }else{
            i++;
        }
    }

    free(B);

}

int main()
{

    int arr[7] = {12, 11, 13, 5, 6, 7, 5};
    int size = sizeof(arr) / sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr, size);
    countSort(arr, size);
    printf("Printing array after sorting:\n");
    displayArray(arr, size);

    return 0;
}