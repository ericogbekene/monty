#include "monty.h"

/**
  * h_line - implement comment handling
  * @line: line read from input
  *
  */

void h_line(char *line)
{
	while(*line && isspace(*line))
	{
		line++;
	}
	if(*line == '#')
	{
		return;
	}
	printf("Processing: %s\n", line);
}

