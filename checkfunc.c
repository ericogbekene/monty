#include "monty.h"

/**
 * check_func - function to return funtion of matching opcode
 * @checkOp: opcode to check for
 *
 * Return: pointer to the function associated with opcode
 */

void (*check_func(char *checkOp))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions_new[] = {
		{ "push", push_node },
		{"pop", pop_node},
		{"pall", print_nodes},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions_new[i].opcode != NULL)
	{
		if (strcmp(instructions_new[i].opcode, checkOp) == 0)
		{
			return (instructions_new[i].f);
		}
		i++;
	}
	return (NULL);

}
