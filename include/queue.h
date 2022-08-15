#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INITAL_SIZE 10

typedef struct Queue
{
    int *arr;
    int capacity;
    int end;
    int front;
}queue;

queue *createQueue();

void enqueue(queue *q, int value);

int dequeue(queue *q);

int q_peek(queue *q);

bool q_isEmpty(queue *q);

bool q_isFull(queue *q);

bool isInQueue(queue *q, int value);

void freeQueue(queue *q);

void printQueue(queue *q);

#endif 