// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int capacity;
    int rear;
    int front;
    int *arr;
};

int isFull(struct DEQueue *q)
{
    return q->size == q->capacity;
}

int isEmpty(struct DEQueue *q)
{
    return q->size == 0;
}

void enqueueFront(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow! Cannot enqueue element to the front.\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->arr[q->front] = val;
        q->size++;
        return;
    }

    if (q->front == 0)
    {

        for (int i = q->rear; i >= q->front; i--)
        {
            q->arr[i + 1] = q->arr[i];
        }

        q->rear++;
        q->size++;
        q->arr[q->front] = val;
        return;
    }

    q->front--;
    q->arr[q->front] = val;
    q->size++;
}

void enqueueRear(struct DEQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow! Cannot add enqueue element to the rear.\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->arr[q->rear] = val;
        q->size++;
        return;
    }

    if (q->rear == q->capacity - 1 && q->front != 0)
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            q->arr[i - 1] = q->arr[i];
        }
        q->arr[q->rear] = val;
        q->front--;
        q->size++;
        return;
    }

    q->rear++;
    q->arr[q->rear] = val;
    q->size++;
}

int dequeueFront(struct DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot dequeue element from front.\n");
        return -1;
    }

    int val = q->arr[q->front];
    q->front++;
    if (q->front == q->rear + 1)
    {
        q->front = -1;
        q->rear = -1;
    }
    q->size--;
    return val;
}

int dequeueRear(struct DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot dequeue element from rear.\n");
        return -1;
    }

    int val = q->arr[q->rear];
    q->rear--;
    if (q->rear == q->front - 1)
    {
        q->front = -1;
        q->rear = -1;
    }
    q->size--;
    return val;
}

int getFront(struct DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot get the front of the queue.\n");
        return -1;
    }

    return q->arr[q->front];
}

int getRear(struct DEQueue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow! Cannot get the rear of the queue.\n");
        return -1;
    }

    return q->arr[q->rear];
}
void display(struct DEQueue *q)
{

    if (isEmpty(q))
    {
        printf("Queue underflow! Queue is empty.\n");
        return;
    }

    printf("Printing queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{

    struct DEQueue *dq = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if (dq == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    dq->capacity = 10;
    dq->front = dq->rear = -1;
    dq->size = 0;
    dq->arr = (int *)malloc(dq->capacity * sizeof(int));

    enqueueFront(dq, 50);
    enqueueFront(dq, 40);
    enqueueFront(dq, 30);
    enqueueFront(dq, 20);
    enqueueFront(dq, 10);
    dequeueFront(dq);
    dequeueFront(dq);
    enqueueRear(dq, 60);
    enqueueRear(dq, 70);
    enqueueRear(dq, 80);
    enqueueRear(dq, 90);
    enqueueRear(dq, 100);
    dequeueRear(dq);
    // enqueueRear(dq,110); // Cannot add as queue is full

    display(dq);
    printf("The size of queue is %d\n", dq->size);
    printf("The index of rear is %d\n", dq->rear);
    printf("The index of front is %d\n", dq->front);
    printf("The value at front is %d\n", getFront(dq));
    printf("The value at rear is %d\n", getRear(dq));
    // Write C code here

    return 0;
}