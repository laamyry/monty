#include "monty.h"
/**
 * mo_mod -  computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 *
 * @stack: Pointer.
 * @line_num: Line number.
 */
void mo_mod(stack_t **stack, unsigned int line_num)
{
	int m, n;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	m = (*stack)->n;
	n = (*stack)->next->n;

	if (m == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = n % m;
	mo_pop(stack, line_num);
}
