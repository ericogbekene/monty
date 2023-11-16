# C - Stacks, Queues - LIFO, FIFO
Alx Stack and Queues collaborative project done using C - Programming Language
# Collaborators
* **ADEYEMI MARVELLOUS**
* **OGBEKENE ERIC**

# Project General Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* You allowed to use a maximum of one global variable
* No more than 5 functions per file
* You are allowed to use the C standard library
* The prototypes of all your functions should be included in your header file called monty.h
* Don’t forget to push your header file
* All your header files should be include guarded
* You are expected to do the tasks in the order shown in the project

# More Info
**Data structures**
Please use the following data structures for this project. Don’t forget to include them in your header file.
The below data structure is used for the project and is included in the header


 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 *

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

# Compilation & Output
* The code will be compiled this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

**The Monty language**
***Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.***

* Monty byte code files

***Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its arguments***

**The monty program**

* Usage: monty file
where file is the path to the file containing Monty byte code
*If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
* If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
***where <file> is the name of the file***
* If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
***where is the line number where the instruction appears.***
***Line numbers always start at 1***
* The monty program runs the bytecodes line by line and stop if either:
***it executed properly every line of the file***
***it finds an error in the file***
***an error occured***
* If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
* You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

# Task

0. push, pall

***Implement the push and pall opcodes.***

*The push opcode*

*The opcode push pushes an element to the stack.*

* Usage: push <int>
***where <int> is an integer***
* if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
***where is the line number in the file***
***You won’t have to deal with overflows. Use the atoi function

*The pall opcode*

***The opcode pall prints all the values on the stack, starting from the top of the stack***

* Usage pall
* Format: see example
* If the stack is empty, don’t print anything
