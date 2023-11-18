#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fileDesc;
	int lineNum = 0, insertData = 0, i;
	char *inputStr = NULL, *token;
	size_t num = 0;
	char **customArray = NULL;
	char *delim = " \t\n";
	stack_t *currentStack;

	(void) currentStack;
	(void) insertData;

	if (argc != 2)
	{
		printf("Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileDesc = fopen(argv[1], "r");
	/* fileDesc = open(argv[1], O_RDONLY); */
	if (fileDesc == NULL)
	{
		printf("Error opening file");
	}

	customArray = malloc(sizeof(char *) * 3);
	if (customArray == NULL)
	{
		perror("Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	/* nread = getline(&inputStr, &num, fileDesc);*/
	while ((getline(&inputStr, &num, fileDesc)) != -1)
	{
		token = strtok(inputStr, delim);
		i = 0;
		while (token != NULL)
		{
			customArray[i++] = token;
			token = strtok(NULL, delim);
		}
		customArray[i] = NULL;
		lineNum++;

		if (strcmp(customArray[0], "push") == 0)
		{
			insertData = atoi(customArray[1]);
			push_node(&currentStack, lineNum, insertData);
		}
		else if (strcmp(customArray[0], "pall") == 0)
		{
			print_nodes(&currentStack, lineNum);
		}
	}
/*
	else
		if (check_func(customArray, &currentStack, lineNum) == 1)
		{
			 failed, print error message
		}
*/
	/* call check function to perform op */
	return (EXIT_SUCCESS);
}
