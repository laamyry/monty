#ifndef _monty_h
#define _monty_h
#define _GNU_SOURCE

#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct general_s - variables.
 *
 * @argu: value.
 * @line: line to input.
 * @file: monty file.

 */
typedef struct general_s
{
	char *argu;
	FILE *file;
	char *line;

} gener_t;

extern gener_t gener;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;

union functype
{
	void (*toponly)(stack_t **top);
	void (*pushmode)(stack_t **top, stack_t **bot, int val, int mode);
	void (*topbot)(stack_t **top, stack_t **bot);
};

typedef struct optype
{
	char *opcode;
	union functype func;
} optype;

typedef struct monty_glob
{
	char *buf;
	unsigned long line_num;
	FILE* scrpt;
} monty_glob;

void run_file(stack_t **stack);
void run_mocode (char *opcode, stack_t **stack, unsigned int line_num);

void mo_push(stack_t **stack, unsigned int line_num);
void mo_pall(stack_t **stack, unsigned int line_num);
void mo_pint(stack_t **stack, unsigned int line_num);
void mo_pop(stack_t **stack, unsigned int line_num);
void mo_swap(stack_t **stack, unsigned int line_num);
void mo_add(stack_t **stack, unsigned int line_num);
void mo_nop(stack_t **stack, unsigned int line_num);
void mo_sub(stack_t **stack, unsigned int line_num);
void mo_div(stack_t **stack, unsigned int line_num);
void mul(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **top, stack_t **bot);
void rotr(stack_t **top, stack_t **bot);
void mo_mul(stack_t **stack, unsigned int line_num);
void mo_mod(stack_t **stack, unsigned int line_num);
void mo_pchar(stack_t **stack, unsigned int line_num);
void mo_pstr(stack_t **stack, unsigned int line_num);

stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif
