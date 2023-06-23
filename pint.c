#include "monty.h"
/**
 * m_pint - prints the value at the top of the stack.
 *
 * @head: head of stack.
 * @counter: number line.
 * Return: nothing.
*/
void m_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.cntnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
