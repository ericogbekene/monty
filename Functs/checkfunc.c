#include "monty.h"

/**
 * check_func - function to return funtion of matching opcode
 * @checkOp: opcode to check for
 * @stack: pointer to the stack
 * @line_number: number of line being read
 *
 * Return: pointer to the function associated with opcode
 */

int check_func(char **checkOp, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions_new[] = {
		{"pop", &pop_node},
		{"pall", &print_nodes},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions_new[i].opcode != NULL)
	{
		if (strcmp(instructions_new[i].opcode, checkOp[0]) == 0)
		{
			instructions_new[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	return (1);

}
