/*
 * Stack implementation based off of Geroge Furgeson's linked list
 */
#include "Stack.h"
#include <stdlib.h>
/**
 * Toplevel Stack structure
 */
typedef struct Stack {
    struct StackNode *first;
}Stack;

/**
 * Structure for each element of a stack
 */
typedef struct StackNode {
    char data;
    struct StackNode *next;
}StackNode;

/**
 * Allocate, initialize and return a new (empty) Stack
 */
Stack *
Stack_new() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->first = NULL;
    return stack;
}

StackNode *
StackNode_new(char data) {
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));
    if (node == NULL) {
	abort();
    }
    node->data = data;
    node->next = NULL;
    return node;
}

/**
 * Free the memory used for the given Stack.
 * If boolean free_data_also is true, also free the data associated with
 * each element.
 */
void
Stack_free(Stack *stack, bool free_data_also) {
    // Free the elements
    StackNode *elt = stack->first;
    while (elt != NULL) {
	StackNode *next = elt->next;
	free(elt);
	elt = next;
    }
    // Free the list itself
    free(stack);
}

/**
 * Return true if the given Stack is empty.
 */
bool
Stack_is_empty(const Stack *stack) {
    return stack->first == NULL;
}

/**
 * Add the given void* value at the front of the given Stack.
 */
void
Stack_push(Stack *stack, char data) {
    StackNode *node = StackNode_new(data);
    node->next = stack->first;
    stack->first = node;
}

/**
 * Remove and return the first element from the given Stack.
 * Returns NULL if the stack is empty.
 */
char
Stack_pop(Stack *stack) {
  char data = '\0';
  if (stack->first != NULL) {
  if (stack->first->data != '\0') {//if there is something on the stack
    data = stack->first->data;
    if (stack->first->next != NULL) {//if theres a 2nd element
      stack->first = stack->first->next;
    }
    else{
      stack->first = NULL;
    }
  }


  }
    return data;
}
