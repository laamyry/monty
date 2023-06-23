#include "monty.h"
/**
 * mo_mul -  multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: double pointer.
 * @line_num: current line number.
 */
void mo_mul(stack_t **stack, unsigned int line_num)
{

	int res;
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	res = tmp->next->n * tmp->n;
	tmp->next->n = res;
	*stack = tmp->next;
	free(tmp);

}
