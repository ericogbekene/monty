#include "monty.h"

void push_node(stack_t **stack, unsigned int line_number, unsigned int data)
{
	stack_t *current;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void) line_number;

	if (new_node == NULL)
	{
		perror("Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new_node->n = data;
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	current = *stack;
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = current;
	current->prev = new_node;
	*stack = new_node;

}
