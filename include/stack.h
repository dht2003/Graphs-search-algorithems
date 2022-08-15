#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INITIAL_SIZE 10

typedef struct Stack
{
    int *arr;
    int capacity;
    int top; 
} stack;

stack *createStack();

void push(stack *s, int value);

int pop(stack *s);

int s_peek(stack *s);

bool s_isEmpty(stack *s);

bool s_isFull(stack *s);

bool isInStack(stack *s, int value);

void freeStack(stack *s);

void printStack(stack *s);

#endif