#include "stack.h"

static const char *errmsg[] = {
    "Stack is not created.",
    "Unable to allocate memmory.",
    "Unable to push, stack is full.",
    "Unable to pop, stack is empty."
};

struct Node
{
    mydata data;
    struct Node *prev;
};
typedef struct Node Node;

Stack* createStack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if(stack == NULL)
    {
        fprintf(stderr, "Error: %s\n", errmsg[1]);
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    stack->created = true;
    return stack;
}

int push(Stack *stack, mydata data)
{
    if(stack == NULL || !stack->created)
    {
        fprintf(stderr, "Error: %s\n", errmsg[0]);
        return 1;
    }

    if(isFull(stack))
    {
        fprintf(stderr, "Error: %s\n", errmsg[2]);
        return 1;
    }

    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = (Node*)(stack->top);
    stack->top = node;
    stack->size++;

    return 0;
}

int pop(Stack *stack, mydata *data)
{
    if(stack == NULL || !stack->created)
    {
        fprintf(stderr, "Error: %s\n", errmsg[0]);
        return 1;
    }

    if(isEmpty(stack))
    {
        fprintf(stderr, "Error: %s\n", errmsg[3]);
        return 1;
    }

    Node *node = stack->top;
    stack->top = node->prev;
    *data = node->data;
    free(node);
    stack->size--;

    return 0;
}

bool isEmpty(Stack *stack)
{
    if(stack == NULL || !stack->created)
    {
        fprintf(stderr, "Error: %s\n", errmsg[0]);
        return 1;
    }

    return stack->size == 0;
}

bool isFull(Stack *stack)
{
    if(stack == NULL || !stack->created)
    {
        fprintf(stderr, "Error: %s\n", errmsg[0]);
        return 1;
    }

    Node *testnode = (Node*)malloc(sizeof(Node));
    bool full = (testnode == NULL);
    if(!full)
        free(testnode);
    return full;
}

void destroyStack(Stack **stack)
{
    if(*stack == NULL || !(*stack)->created)
    {
        fprintf(stderr, "Error: %s\n", errmsg[0]);
        return;
    }

    while(!isEmpty(*stack))
    {
        mydata *temp;
        pop(*stack, temp);
    }
    free(*stack);
    *stack = NULL;
}



