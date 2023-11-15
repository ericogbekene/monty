#include "monty.h"

ssize_t check_the_op(char *op, stack_t **stack, unsigned int n)
{
	switch (op)
	{
		case '1': /*push*/
			push_node(stack, n);
		case '2': /*pop */
			pop_node(stack, n);
		case '3': /*pall */
			print_nodes(stack, n);
		default:
			return (-1); /* op not found, fix later*/
	}
	return (0);

	if (strcmp(op, "push") == 0)
		return (push_node(stack, n));
	else if (strcmp(op, "pop") == 0)
		return (pop_node(stack, n));
	else if (strcmp(op, "pall") == 0)
		return (print_nodes(stack, n)); /*pass lineNumber*/
	else
		return (-1);
}
