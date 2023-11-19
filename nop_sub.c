#include "monty.h"

/**
  *nop_op - Doesn’t do anything.
  *@stack: A double pointer to the top of the stack.
  *@line_number: The line number in the Monty bytecode file
  *where the push operation is called
  */

void nop_op(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
  *sub_node -  Subtracts the top two elements of the stack.
  *@stack: A double pointer to the top of the stack.
  *@line_number: The line number in the monty Bytecode file
  *where the push operation is called.
  */
void sub_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	/*Check if the stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* subtracts the top two elements of the stack */
	(*stack)->next->n += (*stack)->n;

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
