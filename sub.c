#include "monty.h"

/**
 * mo_sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_num: current line number in the file
 */
void mo_sub(stack_t **stack, unsigned int line_num)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}