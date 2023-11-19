#include "monty.h"

/**
  *div_node -  Divide the top two elements of the stack.
  *@stack: A pointer to the top of the stack.
  *@line_number: The line number in the monty Bytecode file
  *where the push operation is called.
  */
void div_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/*Check if the stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* div the sec top  elements of the stack by the top element*/
	(*stack)->next->n /= (*stack)->n;

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  *mul_node -  Multiply the top two elements of the stack.
  *@stack: A double pointer to the top of the stack.
  *@line_number: The line number in the monty Bytecode file
  *where the push operation is called.
  */
void mul_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/*Check if the stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* multiply the second top elements of the stack by the top element*/
	(*stack)->next->n *= (*stack)->n;

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  *mod_node -  Mod the top two elements of the stack.
  *@stack: A pointer to the top of the stack.
  *@line_number: The line number in the monty Bytecode file
  *where the push operation is called.
  */
void mod_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	/*Check if the stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* mod the top two elements of the stack */
	(*stack)->next->n %= (*stack)->n;

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}
