#include "monty.h"

/**
 * check_func - function to return funtion of matching opcode
 * @fpr: file to process
 *
 */

void check_func(FILE *fileDesc)
{

	size_t lineNum = 0;
	int m;
	unsigned int count = 0;
	char *inputStr = NULL;
	ssize_t getline_val;
	char *delim = " \t\n";
	stack_t *stack = NULL;


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

	while((getline_val = getline(&inputStr, &lineNum, fileDesc )) != -1)
	{
		count++;
		delim = strtok(inputStr, " \t\n");
		if (!delim || delim[0] == '#')
			continue;
		for (m = 0; instructions_new[m].opcode; m++)
		{
			if(strcmp(delim, instructions_new[m].opcode == 0))
			{
				instructions_new[m].f(&stack, count);
				break;
			}
		}
	

		if (!instructions_new[m].opcode)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, delim);
			cleanup(fileDesc, inputStr, &stack);
			exit(EXIT_FAILURE);
		}
		free(inputStr);
		inputStr = NULL;
	}
	free(inputStr);
	_free(&stack);

}
