#include "monty.h"
/**
 * free_stack - frees stack.
 *
 * @stack: pointer.
 */
void free_stack(stack_t *stack)
{

	stack_t *curr;

	while (stack != NULL)
	{
		curr = stack;
		stack = stack->next;
		free(curr);
	}

}
