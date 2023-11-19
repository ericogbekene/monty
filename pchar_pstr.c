#include "monty.h"

/**
 * pchar_op - prints the char at the top of the stack, followed by a new line.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file
 * where the push operation is called.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	/* Check if the stack is empty */
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);

	/* Check if the value is in the ASCII table */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c\n", (*stack)->n);

	/* Remove the top element of the stack */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
  *pstr_op - Print string starting at the top of stack
  *@stack: A double pointer to top of the stack
  *@line_number: line number is the Monty bytecode
  */

void pstr_op(stack_t **stack, unsigned int line_number)
{
	/* Check if the stack is empty */
	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	/* Print the string starting at the top of the stack */
	while (*stack)
	{
	/* Check if the value is in the ASCII table */
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pstr, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Print the character at the top of the stack */
	printf("%c", (*stack)->n);

	/* Remove the top element of the stack */
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);

	/* Stop if the value of the element is 0 */
	if (!*stack || (*stack)->n == 0)
		break;
}
