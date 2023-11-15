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
stack_t *push_node(stack_t **stack, int n);
stack_t *pop_node(stack_t **stack, unsigned int line_number);
ssize_t check_the_op(char *op, stack_t **stack, unsigned int n);
void nop(void);
size_t print_nodes(stack_t **stack, unsigned int n);

#endif /* MONTY_H */
