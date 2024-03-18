#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// ---------------------------------------------------
typedef int mydata; // <- change desired datatype here
// ---------------------------------------------------

struct Stack
{
    struct Node *top;
    int size;
    bool created;
};
typedef struct Stack Stack;

// Function that creates a stack.
// Returns a pointer to the created stack.
// Returns NULL if the stack could not be created.
Stack* createStack();

// Functionality of a stack.
int push(Stack*, mydata); 	// 0 - success, 	1 - error
int pop(Stack*, mydata*);	// 0 - success, 	1 - error
bool isEmpty(Stack*); 		// 0 - not empty, 	1 - empty/error
bool isFull(Stack*); 		// 0 - not full, 	1 - full/error

// Function that destroys a stack. Stack pointer is set to NULL.
void destroyStack(Stack**);

/*
	If an error occurs, each function
	also outputs a corresponding error message.
*/
#endif






