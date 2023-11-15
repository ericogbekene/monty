#include "monty.h"

stack_t *pop_node(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;
	stack_t *nextNode;

	if (*stack == NULL)
	{
		perror("Stack Empty\n");
		exit(EXIT_FAILURE); /** or return NULL */
	}

	temp = *stack;

	nextNode = temp->next;
	free(temp);
	nextNode->prev = NULL;
	*stack = nextNode;

	return (*stack);



}
