#include "monty.h"
/**
 * mo_pint - prints the value at the top of the stack.
 *
 * @stack: pointer.
 * @line_num: line number.
*/
void mo_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		free(gener.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
