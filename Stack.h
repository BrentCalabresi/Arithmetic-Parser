#include <stdlib.h>
#include <stdbool.h>
/*
* File: Stack
* Based off of George Furgeson's provided linked list implementation
*/

// Partial declaration
typedef struct Stack Stack;
typedef struct StackNode StackNode;

/**
 * Allocate, initialize and return a new (empty) Stack.
 */
extern Stack *Stack_new();

/**
 * Free the memory used for the given Stack.
 * If boolean free_data_also is true, also free the data associated with
 * each element.
 */
extern void Stack_free(Stack *stack, bool free_data_also);

/**
 * Return true if the given Stack is empty.
 */
extern bool Stack_is_empty(const Stack *stack);

/**
 * Add the given void* value at the front of the given Stack.
 */
extern void Stack_push(Stack *stack, char value);

/**
 * Remove and return the first element from the given Stack.
 * Returns NULL if the list is empty.
 */
extern char Stack_pop(Stack *stack);
