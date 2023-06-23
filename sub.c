#include "monty.h"
/**
 * mo_sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * 
 * @stack: double pointer.
 * @line_num: current line number.
 */
void mo_sub(stack_t **stack, unsigned int line_num)
{
	
	int res;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	res = tmp->next->n - tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);

}
