#include "monty.h"

stack_t *push_node(stack_t **stack, int n)
{
	stack_t *current;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		return (NULL);
	}
	if (*stack == NULL)
	{
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	current = *stack;
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = current;
	current->prev = new_node;
	*stack = new_node;

	return (*stack);

}
