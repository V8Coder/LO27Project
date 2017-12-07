/*Name of the file : stack-lib.h
*Goal of the file : Creation an manipulation of stack
*Authors : Lucas CELANT / Loic MARTIN
*E-mail : lucas.celant@utbm.fr / loic.martin@utbm.fr
*Last modification : 7/12/2017
*/

#ifndef _STACK_LIB_H_
#define _STACK_LIB_H_

#include "tree-lib.h"

typedef struct stack_elem
{
	BTree value;
	struct stack_elem* next;
}Stack_Elem;
typedef Stack_Elem* Stack_Element;

typedef struct stack_head
{
	int size;
	Stack_Element top;
}Stack_Head;
typedef Stack_Head* Stack;

/*
 * Check if the stack is empty
 * @param s a stack
 * @return trus if the stack is empty, false otherwise
 */
bool is_stack_empty(Stack s);

/**
 * Create a new stack
 * @return pointer to a stack
 */
Stack new_stack();

/**
 * Add a value to a stack
 * @param s a stack
 * @param t a tree
 * @return a pointer to the head of the stack
 */
Stack push(Stack s, BTree t);

/**
 * Get the head of the list
 * @param s a stack
 * @return a pointer to a tree node
 */
Stack_Element peek(Stack s);

/**
 * Retrieve an element from the stack
 * @param s the stack where we want to retrieve an element
 * @return the stack with the retrived element
 */
Stack pop(Stack s);

/**
 * Empty the stack
 * @param s a stack
 * @return a stack
 */
Stack empty_stack(Stack s);

/**
 * Delete the stack
 * @param s a stack
 */
void delete_stack(Stack s);

#endif
