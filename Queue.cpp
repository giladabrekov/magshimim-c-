#include "Queue.h"

void initQueue(Queue* q, unsigned int size)
{
    q->arr = new unsigned int[size];
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    q->capacity = size;
}

void cleanQueue(Queue* q)
{
    delete[] q->arr;
    q->arr = nullptr;
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    q->capacity = 0;
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (isFull(q))
    {
        return;
    }

    q->arr[q->rear] = newValue;
    q->rear = (q->rear + 1) % q->capacity;
    q->count++;
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    int value = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;

    return value;
}

bool isEmpty(Queue* s)
{
    return s->count == 0;
}

bool isFull(Queue* s)
{
    return s->count == s->capacity;
}