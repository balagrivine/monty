#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * get_opcode - selects the correct opcode based on the one passed
 * @passed: opcode passed to the program
 * Return: pointer to the function that excutes the opcode passed to the program
 */

void (*get_opcode(char *passed))(stack_t **head, unsigned int num)
{
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rot1", _rot1},
		{"rotr", _rotr},
		{"sub", _sub},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(instruction[i].opcode, passed) == 0)
		{
			break;
		}
	}
	return (instruction[i].f);
}
