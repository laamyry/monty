#include "monty.h"
/**
 * mo_swap - swaps the top two elements of the stack.
 *
 * @stack: pointer.
 * @line_num: line number.
*/
void mo_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		free(gener.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;

	if (tmp->next != NULL)

	tmp->next->prev = *stack;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
