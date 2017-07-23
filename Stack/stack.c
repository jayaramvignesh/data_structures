
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* Stack_Create(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int Stack_Full(struct Stack* stack)
{
    if(stack->top == stack->capacity - 1)
    {
        printf("Stack is full\n");
        return 1;
    }
    else
    {
        return 0;
    }

}


int Stack_Empty(struct Stack* stack)
{
    if(stack->top == -1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}


void Stack_Push(struct Stack* stack, int item)
{
    if (Stack_Full(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int Stack_Pop(struct Stack* stack)
{
    if (Stack_Empty(stack))
        return INT_MIN;

    return stack->array[stack->top--];
}

int main()
{
    struct Stack* stack = Stack_Create(3);
    int popped_value;

    Stack_Push(stack, 10);
    Stack_Push(stack, 20);
    Stack_Push(stack, 30);

    popped_value = Stack_Pop(stack);
    printf("%d popped from stack\n",popped_value);

    return 0;
}
