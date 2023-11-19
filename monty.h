#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define Push 1
#define Pall 2
#define pop 3
#define pint 4

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function prototypes */
void push_node(stack_t **stack, unsigned int line_number, const char *n);
void pop_node(stack_t **stack, unsigned int line_number);
void check_func(FILE *fileDesc);
void print_nodes(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void swap_node(stack_t **stack, unsigned int line_number);
void add_node(stack_t **stack, unsigned int line_number);
void div_node(stack_t **stack, unsigned int line_number);
void mul_node(stack_t **stack, unsigned int line_number);
void mod_node(stack_t **stack, unsigned int line_number);
void nop_op(stack_t **stack, unsigned int line_number);
void sub_node(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
void h_line(char *line);
void _free(stack_t **stack);
void cleanup(FILE *fileDesc, char *CustomArray, stack_t **stack);

#endif /* MONTY_H */
