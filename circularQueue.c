#include <stdio.h>
#include <stdlib.h>

// Circular Queue ADT
struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

// Function to check whether queue is full
int isFull(struct circularQueue *cq)
{
    if ((cq->rear + 1) % cq->size == cq->front)
    {
        return 1;
    }
    return 0;
}

// Function to check whether queue is empty
int isEmpty(struct circularQueue *cq)
{
    if (cq->front == cq->rear)
    {
        return 1;
    }

    return 0;
}

// Adding elements to the rear of the queue
void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow! Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
    }
}

// Removing elements from the front of the queue;
int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue undeflow! Queue is empty.\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }

    return a;
}

// Returns the frontmost element of the queue
int queueFront(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue undeflow! Queue is empty. Cannot return front element\n");
        return -1;
    }

    return q->arr[(q->front+1)%q->size];
}

// Returns the rearmost element of the queue
int queueRear(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue undeflow! Queue is empty. Cannot return rear element\n");
        return -1;
    }

    return q->arr[q->rear];
}

int main()
{

    struct circularQueue q;
    q.size = 5;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Checking whether queue is initialized and empty...\n");

    int check = isEmpty(&q);

    if (check)
    {
        printf("Queue is initialized suceessfully and is empty for now\n");
    }
    else
    {
        printf("Something went wrong with initialization. Check the code\n");
    }

    // Enqueuing elements;
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 18);
    enqueue(&q, 19);
    // enqueue(&q, 20); // Even though size is 5 the 5th element cannot be pushed in circualar queue as 1 index is reserved for front

    printf("Printing the front side of the element %d\n", queueFront(&q));
    printf("Printing the rear side of the element %d\n", queueRear(&q));

    // Dequeuing element to check whether FIFO is implemented. Similar to traversal of queue
    while (!isEmpty(&q))
    {
        printf("Dequeuing element %d\n", dequeue(&q));
    }

    // Return -1 as queue is empty.
    // printf("Printing the front side of the element %d\n", queueFront(&q));
    // printf("Printing the rear side of the element %d\n", queueRear(&q));

    return 0;
}