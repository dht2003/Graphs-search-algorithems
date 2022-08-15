#include "stack.h"

stack *createStack() {
    stack *s = (stack *) malloc(sizeof(stack));
    if (s == NULL) {
        fprintf(stderr,"Cannot malloc stack\n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->capacity = INITIAL_SIZE;
    s->arr = (int *) malloc(sizeof(int) * INITIAL_SIZE);
    if (s->arr == NULL) {
        fprintf(stderr, "Cannot allocate stack's array\n");
        exit(EXIT_FAILURE);
    }
    return s;
}

void freeStack(stack *s) {
    free(s->arr);
    free(s);
}

bool s_isEmpty(stack *s) {
    return s->top == -1.0;
}

bool s_isFull(stack *s) {
    return (s->capacity - 1.0) == s->top;
}

bool isInStack(stack *s, int value) {
    if (s_isEmpty(s)) return false;
    for (int i = 0; i <= s->top; i++) 
        if (s->arr[i] == value) return true;
    return false;
}

int s_peek(stack *s) {
    if (!s_isEmpty(s))
        return s->arr[s->top];

    fprintf(stderr,"Stack is empty");
    exit(EXIT_FAILURE);
}

int pop(stack *s) {
    if (!s_isEmpty(s)) {
        return s->arr[s->top--];
    }

    fprintf(stderr,"Stack is empty");
    exit(EXIT_FAILURE);
}

void push(stack *s, int value) {
    if (s_isFull(s)) {
        s->capacity *= 2;
        s->arr =  realloc(s->arr,sizeof(int) * s->capacity);
    }
    s->arr[++(s->top)] = value;
}


void printStack(stack *s) {
    if (s_isEmpty(s)) return;
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) 
        printf("%i ", s->arr[i]);
    printf("\n");
}
