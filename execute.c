#include "monty.h"

/**
 * execute_file - reads and executes opcodes from a file
 * @stack: pointer to the top of the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_num = 0;

	while ((nread = getline(&gener.line, &len, gener.file)) != -1)
	{
		line_num++;
		opcode = strtok(gener.line, " \t\r\n\a");
		gener.argu = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_mocode(opcode, stack, line_num);
	}
}

/**
 * execute_mocode - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer to the top of the stack
 * @line_num: line number of the opcode
 */
void execute_mocode(char *opcode, stack_t **stack, unsigned int line_num)
{
	instruction_t instructions[] = {
		{"push", mo_push},
		{"pall", mo_pall},
		{"pint", mo_pint},
		{"pop", mo_pop},
		{"swap", mo_swap},
		{"nop", mo_nop},
		{"add", mo_add},
		{"sub", mo_sub},
		{"div", mo_div},
		{"mul", mo_mul},
		{"mod", mo_mod},
		{"pchar", mo_pchar},
		{"pstr", mo_pstr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	free_stack(*stack);
	fclose(gener.file);
	free(gener.line);
	exit(EXIT_FAILURE);
}
