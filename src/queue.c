#include "queue.h"

queue *createQueue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->capacity = INITAL_SIZE;
    q->end = 0;
    q->front = 0;
    if (q == NULL) {
        fprintf(stderr,"Cannot allocate queue\n");
        exit(EXIT_FAILURE);
    }
    q->arr = (int *) malloc((sizeof(int) * INITAL_SIZE));
    if (q->arr == NULL) {
        fprintf(stderr, "Cannot allocate queue's array\n");
        exit(EXIT_FAILURE);
    }
    return q;
}

void freeQueue(queue *q) {
    free(q->arr);
    free(q);
}

bool q_isEmpty(queue *q) {
    return q->end == q->front;
}

bool q_isFull(queue *q) {
    return (q->capacity - 1.0) == q->end;
}

bool isInQueue(queue *q, int value) {
    for (int i = q->front; i <= q->end; i++) 
        if (q->arr[i] == value) return true;
    return false;
}



int q_peek(queue *q) {
    if (!q_isEmpty(q)) 
        return q->arr[q->front];
    
    fprintf(stderr,"Queue is empty\n");
    exit(EXIT_FAILURE);
}

int dequeue(queue *q) {
    if (!q_isEmpty(q)) 
        return q->arr[q->front++];

    fprintf(stderr,"Queue is empty\n");
    exit(EXIT_FAILURE); 

}

void enqueue(queue *q , int value) {
    if (q_isFull(q)) {
        q->capacity *= 2;
        int *arr = (int *) malloc(sizeof(int) * q->capacity);
        if (arr == NULL) {
            fprintf(stderr, "Cannot allocate queue's array\n");
            exit(EXIT_FAILURE);
        }
        for (int i = q->front; i <= q->end; i++) 
            arr[i - q->front] = q->arr[i];
        free(q->arr);
        q->arr = arr; 
        q->end = q->end - q->front;
        q->front = 0;
    }
    q->arr[(q->end)++] = value;

}


void printQueue(queue *q) {
    if (q_isEmpty(q)) return;
    printf("Queue: ");
    for (int i = 0; i < q->end; i++) 
        printf("%i ", q->arr[i]);
    printf("\n");
}