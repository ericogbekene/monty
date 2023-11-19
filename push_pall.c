#include "monty.h"

/**
 * push_node - Pushes a new element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the Monty bytecode file
 * where the push operation is called.
 * @n: Is a character pointer
 * Return - Always Void
 */


void push_node(stack_t **stack, unsigned int line_number, const char *n)
{
	/*stack_t *current;*/
	stack_t *new_node = malloc(sizeof(stack_t));
	int numb = atoi(n);

	if (numb == 0 && *n != '0')
	{
		fprintf(stderr, "L%d:usage:push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*
	 * if (new_node == NULL)
	  {
	  fprintf("Error allocating memory\n");
	  exit(EXIT_FAILURE);
	  }
	  */

	/*current = *stack;*/

	new_node->n = numb;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;

}

#include "monty.h"

/**
 * print_nodes - prints all nodes in stack
 * @stack: pointer to a stack_t
 * @line_number: line Number
 *
 * Return: void || number of nodes printed
 */

void print_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	/*
	 * if (*stack == NULL)
	   {
	   fprintf(stderr, "List is empty\n");
	   exit(EXIT_FAILURE);
	   }
	   */
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
