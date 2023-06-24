#include "monty.h"
/**
 * add_node - adds new node.
 *
 * @stack: pointer to pointer.
 * @n: add value.
 * Return: pointer.
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *n_node;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	n_node->n = n;
	n_node->prev = NULL;

	if (*stack == NULL)
		n_node->next = NULL;
	else
	{
		n_node->next = *stack;
		(*stack)->prev = n_node;
	}
	*stack = n_node;

	return (n_node);
}
