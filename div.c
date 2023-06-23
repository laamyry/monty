#include "monty.h"

/**
 * mo_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_num: current line number in the file
 */
void mo_div(stack_t **stack, unsigned int line_num)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	result = temp->next->n / temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
