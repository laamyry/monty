#include "monty.h"

/**
 * mo_pchar - prints the character at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_num: current line number of the opcode in the Monty file
 */
void mo_pchar(stack_t **stack, unsigned int line_num)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}
