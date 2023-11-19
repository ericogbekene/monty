#include "main.h"
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
		free(curr_node);
		current = next_node;
	}
	*stack = NULL;
}

/**
 * cleanup - Function to free allocated memory and close the file
 * @fp: File to process
 * @line: Memory to be freed
 * @stack: doubly linked list
 */

void cleanup(FILE *fp, char *line, stack_t **stack)
{
	free(line);
	free_stack(stack);
	fclose(fp);
}
