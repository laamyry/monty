#include "monty.h"

/**
 * mo_mul - multiplies the second top element of the stack with the top element
 * @stack: double pointer to the head of the stack
 * @line_num: current line number in the file
 */
void mo_mul(stack_t **stack, unsigned int line_num)
{
	int result;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	result = tmp->next->n * tmp->n;
	tmp->next->n = result;
	*stack = tmp->next;
	free(tmp);
}
