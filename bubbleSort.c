#include<stdio.h>

void displayArray(int* a, int size){
    printf("Printing array elements: |");

    for(int i=0;i<size;i++){
        printf(" %d |",a[i]);
    }

    printf("\n");
}


void bubbleSort(int* arr, int size){
    int temp=0;
    for(int i=0;i<size-1;i++){
         for(int j=0;j<size-i-1;j++){
             if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
             }
         }
    }
}

void adaptiveBubbleSort(int *arr, int size)
{
    int temp = 0;
    int isSorted=1;
    printf("Running adaptive bubbleSort\n");
    for (int i = 0; i < size - 1; i++)
    {
        printf("Running %d pass\n", i+1);
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted=0;
            }
        }

        if(isSorted==1) return;
    }
}

int main(){
   int arr[5]={12,54,74,86,9};
   int size=sizeof(arr)/sizeof(int);
   

   printf("Printing array before sorting:\n");
   displayArray(arr,size);
   bubbleSort(arr,size);
   printf("Printing array after sorting:\n");
   displayArray(arr,size);
   adaptiveBubbleSort(arr,size);


   
   return 0;
}