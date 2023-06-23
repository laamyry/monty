#include "monty.h"

/**
 * mo_mod - computes the modulus of the second top element of the stack
 *          with the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_num: line number of the opcode
 */
void mo_mod(stack_t **stack, unsigned int line_num)
{
	int a, b;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = b % a;
	mo_pop(stack, line_num);
}