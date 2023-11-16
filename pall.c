#include "monty.h"

/**
 * print_nodes - prints all nodes in stack
 * @stack: pointer to a stack_t
 *
 * Return: void || no of nodes printed
 */

ssize_t print_nodes(stack_t **stack)
{
	size_t count = 0;
	stack_t *current;

	if (*stack == NULL)
	{
		perror("List is empty\n");
		return (-1);
	}
	current = *stack;

	while (current->next != NULL)
	{
		printf("%d\n", current->n);
		count++;
	}

	return (count);
}
