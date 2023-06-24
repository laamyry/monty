#include "monty.h"
/**
 * run_file - reads and executes opcodes.
 * 
 * @stack: pointer.
 */
void run_file(stack_t **stack)
{
	char *opcode = NULL;
	unsigned int line_num = 0;
	size_t leng = 0;
	ssize_t nread;

	while ((nread = getline(&gener.line, &leng, gener.file)) != -1)
	{
		line_num++;
		opcode = strtok(gener.line, " \t\r\n\a");
		gener.argu = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		run_mocode (opcode, stack, line_num);
	}
}

/**
 * run_mocode  - executes opcode.
 *
 * @opcode: opcode.
 * @stack: pointer.
 * @line_num: line number.
 */
void run_mocode (char *opcode, stack_t **stack, unsigned int line_num)
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
	int m;

	for (m = 0; instructions[m].opcode != NULL; m++)
	{
		if (strcmp(opcode, instructions[m].opcode) == 0)
		{
			instructions[m].f(stack, line_num);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
	free_stack(*stack);
	fclose(gener.file);
	free(gener.line);
	exit(EXIT_FAILURE);
}
