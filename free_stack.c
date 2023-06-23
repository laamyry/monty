#include "monty.h"

/**
 * free_stack - frees a stack_t list
 * @stack: pointer to the top of the stack
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
