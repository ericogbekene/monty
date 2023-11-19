#include "monty.h"
/**
 * _free - Function to free the stacks
 * @stack: doubly linked list to be free
 */

void _free(stack_t **stack)
{
	stack_t *current = *stack, *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

/**
 * cleanup - Function to free allocated memory and close the file
 * @fileDesc: File to process
 * @customArray: Memory to be freed
 * @stack: doubly linked list
 */

void cleanup(FILE *fileDesc, char *customArray, stack_t **stack)
{
	free(customArray);
	_free(stack);
	fclose(fileDesc);
}
