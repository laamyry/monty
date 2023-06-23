#include "monty.h"

/**
 * mo_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_num: current line number in the file
 */
void mo_div(stack_t **stack, unsigned int line_num)
{
	int res;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	res = tmp->next->n / tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);
}
