#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fileDesc;
	int lineNum = 0, insertData = 0;
	char *inputStr = NULL;
	size_t num = 0;
	ssize_t nread = 0;
	char **customArray = NULL;
	char *delim = " \t\n";
	stack_t *currentStack;

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

	/* nread = getline(&inputStr, &num, fileDesc);*/
	while ((nread = getline(&inputStr, &num, fileDesc)) != -1)
	{
		customArray = malloc(sizeof(char *) * 5);
		if (customArray == NULL)
		{
			perror("Error allocating memory");
		}
		customArray[0] = strtok(inputStr, delim);
		/* something wrong with this tokenization */
		/*while (customArray[i] != NULL)
		{
			customArray[i] = strtok(NULL, delim);
			i++;
		}*/
		printf("opcode is %s\n", customArray[0]);
		lineNum++;
		printf("Line number : %d\n", lineNum);
	}

	 /* ssize_t opReturn = check_the_op(customArray[0], &currentStack, unsigned int n); */
	/* call check function to perform op */

	if (strcmp(customArray[0], "Push") == 0)
	{
		insertData = atoi(strtok(NULL, " "));
		/*currentStack = malloc(sizeof(stack_t));*/ /*no need to malloc */
		/*if (currentStack == NULL)*/
		/*{
			perror("Error allocating memory\n");
		}*/
		currentStack = push_node(&currentStack, insertData);
		if (currentStack == NULL)
		{
			perror("Error adding to stack\n");
			exit(EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}
