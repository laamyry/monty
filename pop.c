#include "monty.h"
/**
 * mo_pop -  removes the top element of the stack.
 *
 * @stack: pointer.
 * @line_num: line number.
 **/
void mo_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		free(gener.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;

	free(*stack);

	*stack = tmp;
	
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}
