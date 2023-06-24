#include "monty.h"
/**
 * mo_pchar - prints the char at the top of the stack.
 *
 * @stack: pointer.
 * @line_num: current line number.
 */
void mo_pchar(stack_t **stack, unsigned int line_num)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	int value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
	
}