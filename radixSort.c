#include<stdio.h>
#include<stdlib.h>
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

int getMax(int *A,int size){
    int max=A[0];
    for(int i=1;i<size;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}

void countSort(int *A,int size,int exp){

    int *output=(int*)malloc(size*sizeof(int));
    int i,count[10]={0};
    
    for(i=0;i<size;i++){
        count[A[i]/exp%10]++;
    }

    i=0;
    int j=0;
    int k=0;

    while(i<10){
        j=0;
        while(count[i]>0 && j<size){
            if(A[j]/exp%10==i){
                output[k]=A[j];
                k++;
                count[i]--;
            }
            j++;
        }
        i++;
    }
    
    for(int i=0;i<size;i++){
        A[i]=output[i];
    }
    free(output);

}


void radixSort(int *A,int size){

    int max=getMax(A,size);

    for(int exp=1;max/exp>0;exp*=10){
        countSort(A,size,exp);
    }
}


int main(){

    int arr[]={170,45,75,90,802,24,2,66};
    int size=sizeof(arr)/sizeof(int);

    printf("Printing array before sorting:\n");
    displayArray(arr,size);
    radixSort(arr,size);
    printf("Printing array after sorting:\n");
    displayArray(arr,size);


    
   return 0;
}