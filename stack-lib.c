/**Name of the file : stack-lib.h
*Goal of the file : Creation an manipulation of stack
*Authors : Lucas CELANT / Loic MARTIN
*E-mail : lucas.celant@utbm.fr / loic.martin@utbm.fr
*Last modification : 7/12/2017
*/

#include <stdlib.h>
#include "stack-lib.h"


bool is_stack_empty(Stack s)
{
	return s->top == NULL ? true : false;
}

Stack new_stack()
{
	Stack s = (Stack)malloc(sizeof(Stack_Head));
	s->size = 0;
	return s;
}

Stack push(Stack s, BTree t)
{
	Stack_Element se = (Stack_Element)malloc(sizeof(Stack_Elem));
	se->next = NULL;
	se->value = t;
	s->size++;
	if(is_stack_empty(s))
		s->top = se;
	else {
		se->next = s->top;
		s->top = se;
	}
	return s;
}

Stack_Element peek(Stack s)
{
	return s->top;
}

Stack pop(Stack s)
{
	Stack_Element se;
	if(is_stack_empty(s) == false){
		se = s->top;
		s->top = se->next;
		free(se);
	}
	return s;
}

Stack empty_stack(Stack s)
{
	while(is_stack_empty(s) == false)
		pop(s);
	return s;
}

void delete_stack(Stack s)
{
	empty_stack(s);
	free(s);
}
