#include<stdio.h>
#include<stdlib.h>

// Linked list Node structure
struct Node{
    int data;
    struct Node* next;
};

// Queue strructure using linked list
struct Queue{
    struct Node* front;
    struct Node* rear;

};

// Enqueue function to add elements to the rear of the queue
void enqueue(struct Queue* q, int val){
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode==NULL){
        printf("Queue overflow! Cannot allocate memory for new node\n");
        return;
    }

    newNode->data=val;
    newNode->next=NULL;
    if(q->rear==NULL){
        q->front=newNode;
        q->rear=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

// Function to return the frontmost element of the queue
int queueFront(struct Queue* q){
    if(q->front==NULL){
        printf("Queue underflow! Queue is empty. Cannot return front element\n");
        return -1;
    }

    return q->front->data;
}

// Function to return the rearmost element of the queue 
int queueRear(struct Queue* q){
    if(q->rear==NULL){
        printf("Queue underflow! Queue is empty. Cannot return rear element\n");
        return -1;
    }

    return q->rear->data;
}

// Dequeue function to remove elements from the front of the queue (FIFO)
int dequeue(struct Queue* q){
    if(q->front==NULL){
        printf("Queue underflow! Queue is empty. Cannot dequeue element\n");
        return -1;
    }
    struct Node* temp=q->front;
    int val=temp->data;
    q->front=q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

// Function to display the elements of the queue
void display(struct Queue* q){
    if(q->front==NULL){
        printf("Queue is empty. Nothing to display\n");
        return;
    }

    struct Node* temp= q->front;
    printf("Queue elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}

int main(){
   struct Queue* q= (struct Queue*)malloc(sizeof(struct Queue));

   if (q == NULL)
   {
       printf("Memory allocation failed\n");
       return 1;
   }

   // Initialize the queue
   q->front=NULL;
   q->rear=NULL; 

   // Enqueue elements to the queue
   enqueue(q,10);
   enqueue(q,20);   
   enqueue(q,30);   
   enqueue(q,40);   
   enqueue(q,50);   
   enqueue(q,60);   

   // Dequeue elements from the queue and display the dequeued element
   printf("Dequeued element is: %d\n",dequeue(q));
//    printf("Dequeued element is: %d\n",dequeue(q));
//    printf("Dequeued element is: %d\n",dequeue(q));
//    printf("Dequeued element is: %d\n",dequeue(q));
//    printf("Dequeued element is: %d\n",dequeue(q));
//    printf("Dequeued element is: %d\n",dequeue(q));
   display(q);

   // Display the front and rear elements of the queue
   printf("Front element is: %d\n",queueFront(q));
   printf("Rear element is: %d\n",queueRear(q));

   // Free all remaining nodes
   while (q->front != NULL)
   {
       printf("Dequeued element is: %d\n", dequeue(q));
   }

   // Free Queue structure itself
   free(q);

   return 0;
}