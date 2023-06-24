#include "monty.h"
/**
 * mo_push - pushes an element to the stack.
 *
 * @stack: pointer.
 * @line_num: current line number.
 */
void mo_push(stack_t **stack, unsigned int line_num)
{
	int m;

	if (gener.argu == NULL || !is_number(gener.argu))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_stack(*stack);
		fclose(gener.file);
		free(gener.line);
		exit(EXIT_FAILURE);
	}

	m = atoi(gener.argu);
	if (add_node(stack, m) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(gener.file);
		free(gener.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - checks string is number.
 *
 * @str: string.
 * Return: 1.
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
	{
		return (0);
	}

	if (*str == '-' || *str == '+')
	{
		str++;
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}

		str++;
	}

	return (1);
}
