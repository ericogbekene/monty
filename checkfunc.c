#include "monty.h"

/**
 * check_func - function to return funtion of matching opcode
 * @opcode: opcode to check for
 *
 * Return: pointer to the function associated with opcode
 */

stack_t (*check_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions_new[] = {
		{ "push", push_node },
		{"pop", pop_node},
		{"pall", print_nodes},
		{NULL, NULL}
	};

	int i;

	while (instructions_new[i].opcode != NULL)
	{
		if (strcmp(instructions_new[i].opcode, opcode) == 0)
		{
			return (instructions_new[i].f);
		}
		i++;
	}
	return (NULL);

}
