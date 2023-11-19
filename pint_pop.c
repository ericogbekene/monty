#include "monty.h"

/**
 * pint_op - Prints the value at the top of the stack, followed by a new line.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file
 * where the push operation is called.
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

#include "monty.h"

/**
 * pop_node - Removes the top element of the stack
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file
 * where the push operation is called.
 */

void pop_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	/*stack_t *nextNode;*/

	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE); /** or return NULL */
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);

	/*return (*stack);*/
}
