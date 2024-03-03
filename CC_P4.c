// To design a circular queue to implement -Enqueue, -Dequeue, -Front, -Rear we are using static array not dynamic for this//
#include <stdio.h>
#define capacity 20

typedef struct queue
{
    int arr[20];
    int front;
    int rear;
    int size;
} Queue;

void initialiseQ(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue *q, int data)
{
    q->rear = (q->rear + 1) % capacity;
    q->arr[q->rear] = data;
    q->size++;
}

int dequeue(Queue *q)
{
    if (q->size == 0)
    {
        printf("Underfolw");
    }
    else
    {
        int del_ele = q->arr[q->front];
        q->front = (q->front + 1) % capacity;
        q->size--;
        return del_ele;
    }
}

int peek(Queue *q)
{
    if (q->size == 0)
    {
        printf("Stack is Empty");
    }
    else
    {
        return q->arr[q->front];
    }
}

void display(Queue *q)
{
    if (q->size == 0)
    {
        printf("Stack is Empty");
    }
    else
    {
        int i;
        printf("Queue: ");
        for (i = 0; i < q->size; i++)
        {
            printf("%d ", q->arr[(q->front + i) % capacity]);
        }
    }
}

void main()
{
    Queue q;
    initialiseQ(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);
    printf("\nDeleted ele: %d\n", dequeue(&q));
    display(&q);
}
