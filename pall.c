#include "monty.h"
/**
 * mo_pall - prints all the values on the stack.
 *
 * @stack: pointer.
 * @line_num: line number.
 */
void mo_pall(stack_t **stack, unsigned int line_num)
{

	stack_t *curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
		(void)line_num;
	}

}
