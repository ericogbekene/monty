#include "monty.h"

/**
 * check_func - function to return funtion of matching opcode
 * @fpr: file to process
 *
 */

void check_func(FILE *fp)
{

	int lineNum = 0, insertData = 0, i;
	char *inputStr = NULL, *token;
	size_t num = 0;
	char **customArray = NULL;
	char *delim = " \t\n";
	stack_t *currentStack;

	(void) currentStack;
	(void) insertData;


	instruction_t instructions_new[] = {
		{"pop", pop_node},
		{"pall", print_nodes},
		{"push", push_node},
		{"pint", pint_op},
		{"swap", swap_node},
		{"add", add_node},
		{"nop", nop_op},
		{"sub", sub_node},
		{"div", div_node},
		{"mul", mul_node},
		{"mod", mod_node},
		{"#", h_line},
		{"pchar", pchar_op},
		{"pstr", pstr_op},
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
