#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
};

int isFull(struct DEQueue *dq)
{
    return (dq->size == dq->capacity);
}

int isEmpty(struct DEQueue *dq)
{
    return (dq->size == 0);
}

void enqueueFront(struct DEQueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("DEQueue overflow! Cannot enqueue at front\n");
        return;
    }

    dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    dq->array[dq->front] = val;
    dq->size++;
}

void enqueueRear(struct DEQueue *dq, int val)
{
    if (isFull(dq))
    {
        printf("DEQueue overflow! Cannot enqueue at rear\n");
        return;
    }

    dq->array[dq->rear] = val;
    dq->rear = (dq->rear + 1) % dq->capacity;
    dq->size++;
}

int dequeueFront(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue underflow! Cannot dequeue from front\n");
        return -1;
    }

    int val = dq->array[dq->front];
    dq->front = (dq->front + 1) % dq->capacity;
    dq->size--;
    return val;
}

int dequeueRear(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue underflow! Cannot dequeue from rear\n");
        return -1;
    }

    dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    int val = dq->array[dq->rear];
    dq->size--;
    return val;
}

int getFront(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue is empty! Cannot get front element\n");
        return -1;
    }

    return dq->array[dq->front];
}

int getRear(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue is empty! Cannot get rear element\n");
        return -1;
    }

    return dq->array[(dq->rear - 1 + dq->capacity) % dq->capacity];
}

void display(struct DEQueue *dq)
{
    if (isEmpty(dq))
    {
        printf("DEQueue is empty! Nothing to display\n");
        return;
    }

    printf("DEQueue elements are: ");
    for (int i = 0; i < dq->size; i++)
    {
        int index = (dq->front + i) % dq->capacity;
        printf("%d ", dq->array[index]);
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

    dq->capacity = 5;
    dq->front = 0;
    dq->rear = 0;
    dq->size = 0;
    dq->array = (int *)malloc(dq->capacity * sizeof(int));
    if (dq->array == NULL)
    {
        printf("Memory allocation for array failed\n");
        free(dq);
        return 1;
    }

    enqueueRear(dq, 10);
    enqueueRear(dq, 20);
    enqueueFront(dq, 5);
    enqueueFront(dq, 35);
    enqueueFront(dq, 55);

    // enqueueFront(dq, 0);  // Queue overflow! Cannot enqueue at front
    // enqueueRear(dq, 25); // Queue overflow! Cannot enqueue at rear

    display(dq);
    
    dequeueFront(dq);
    dequeueRear(dq);

    display(dq);

    printf("Front element: %d\n", getFront(dq));
    printf("Rear element: %d\n", getRear(dq));

    return 0;
}