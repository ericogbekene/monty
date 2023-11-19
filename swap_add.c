#include "monty.h"

/**
  *swap_node -  Swaps the top two elements of the stack.
  *@stack: A double pointer to the top of the stack
  *@line_number: The line number in the Monty bytecode file
  *where the push operation is called
  */
void swap_node(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
  *add_node -  Adds the top two elements of the stack.
  *@stack: A pointer to the top of the stack.
  *@line_number: The line number in the monty Bytecode file
  *where the push operation is called.
  */
void add_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	/*Check if the stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add the top two elements of the stack */
	(*stack)->next->n += (*stack)->n;

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
