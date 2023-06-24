#include "monty.h"
/**
 * mo_add - adds the top two elements of the stack
 *
 * @stack: pointer.
 * @line_num: line number.
 **/
void mo_add(stack_t **stack, unsigned int line_num)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		free(gener.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	mo_pop(stack, line_num);

}
