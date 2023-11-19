#include "monty.h"

/**
 * print_nodes - prints all nodes in stack
 * @stack: pointer to a stack_t
 * @line_number: line Number
 *
 * Return: void || no of nodes printed
 */

void print_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "List is empty\n");
		exit(EXIT_FAILURE);
	}
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
