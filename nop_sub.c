#include "monty.h"

/**
  *nop_op - Doesn’t do anything.
  *@stack: A double pointer to the top of the stack.
  *@line_num: The line number in the Monty bytecode file
  *where the push operation is called
  */

void nop_op(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

