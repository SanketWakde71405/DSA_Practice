#include<stdio.h>
#include<stdlib.h>

// ADT for Linear Queue
struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};

// Checks whether queue is full
int isFull(struct Queue* q){
    if(q->r== q->size-1){
        return 1;
    }

    return 0;
}

// Checks whether queue is empty
int isEmpty(struct Queue *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

// Enqueue function for linear queue 
void enqueue(struct Queue* q, int val){
    if(isFull(q)){
        printf("Queue overflow. Queue is full\n");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

// Dequeue function for linear queue
int dequeue(struct Queue* q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue underflow. Queue is empty\n");
    }else{
        q->f++;
        a= q->arr[q->f];
    }

    return a;
}

int queueFront(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue undeflow! Queue is empty. Cannot return front element.\n");
        return -1;
    }

    return q->arr[q->f+1];
    
}

int queueRear(struct Queue* q){
    if (isEmpty(q))     
    {
        printf("Queue undeflow! Queue is empty. Cannot return rear element.\n");
        return -1;
    }
    
    return q->arr[q->r];
}

int main(){
   struct Queue q;
   q.size=100;
   q.f=q.r=-1;
   q.arr= (int*) malloc(q.size*sizeof(int));
   
   printf("Checking whether queue is initialized and empty...\n");

   int check= isEmpty(&q);

   if (check)
   {
    printf("Queue is initialized suceessfully and is empty for now\n");
   }else{
    printf("Something went wrong with initialization. Check the code\n");
   }

   // Enqueuing elements;
   enqueue(&q,12);
   enqueue(&q,15);
   enqueue(&q,18);
   
   printf("Printing the front element %d\n", queueFront(&q));
   printf("Printing the rear element %d\n", queueRear(&q));

   // Dequeuing element to check whether FIFO is implemented. Similar to traversal of queue
   while(!isEmpty(&q)){
     printf("Dequeuing element %d\n", dequeue(&q));
   }

   // val will be -1. Will generate a message "Queue underflow. Queue is empty"
   // int val =dequeue(&q);
   
   
   return 0;
}