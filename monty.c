#include "monty.h"
int main(int argc, char **argv);

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */


int main(int argc, char **argv)
{
	FILE *fileDesc;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fileDesc = fopen(argv[1], "r");
	/* fileDesc = open(argv[1], O_RDONLY); */
	if (fileDesc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	check_func(fileDesc);

	cleanup(fileDesc, NULL, &stack);

	return (EXIT_SUCCESS);
}
