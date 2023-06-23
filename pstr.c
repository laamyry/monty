#include "monty.h"

/**
 * mo_pstr - prints the string starting at the top of the stack,
 *           followed by a new line
 * @stack: double pointer to the top of the stack.
 * @line_num: current line number of the opcode in the Monty file
 */
void mo_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;
	(void) line_num;

	while (curr && curr->n > 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}
