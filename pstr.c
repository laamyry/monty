#include "monty.h"
/**
 * mo_pstr -  prints the string starting at the top of the stack.
 *
 * @stack: double pointer.
 * @line_num: current line number.
 * Return: void.
 */
void mo_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *curr = *stack;

	(void)line_num;

	for (; curr && curr->n > 0 && curr->n <= 127; curr = curr->next)
	{
		putchar(curr->n);
	}
	putchar('\n');
}
