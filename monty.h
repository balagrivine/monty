#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <inttypes.h>

/**
 * struct stack_s - head linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: head linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: head linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: head linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t var;

/**                                                                                 * struct instruction_s - opcode and its function                                   * @opcode: the opcode                                                              * @f: function to handle the opcode                                                *                                                                                  * Description: opcode and its function                                             * for stack, queues, LIFO, FIFO                                                    */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t add_end(stack_t **head, const int n);
stack_t add_beginning(stack_t **head, const int n);
void free_list(stack_t **head);

void _push(stack_t **stack, unsigned int num);
void _pall(stack_t **stack, unsigned int num);
void _pint(stack_t **head, unsigned int num);
void _pop(stack_t **head, unsigned int num);
void _swap(stack_t **head, unsigned int num);
void _queue(stack_t **head, unsigned int num);
void _stack(stack_t **head, unsigned int num);
void _add(stack_t **head, unsigned int num);
void _nop(stack_t **head, unsigned int num);
void _sub(stack_t **head, unsigned int num);
void _div(stack_t **head, unsigned int num);
void _mul(stack_t **head, unsigned int num);
void _mod(stack_t **head, unsigned int num);
void _pchar(stack_t **head, unsigned int num);
void _pstr(stack_t **head, unsigned int num);
void _rot1(stack_t **head, unsigned int num);
void _rotr(stack_t **head, unsigned int num);

void (*get_opcode(char *passed))(stack_t **head, unsigned int num);
void free_var(void);

#endif
