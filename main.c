#include "monty.h"
#include <stdio.h>
#ifdef _POSIX_C_SOURCE
#define _GNU_SOURCE
#include <stdio.h>
#endif

/**
 * start_var - initialize the global variables
 * @fd: pointer to the file descriptor to be opereted on
 * Return: nothing
 */

void start_var(FILE *fd)
{
	var.lifo = 1;
	var.cont = 1;
	var.arg = NULL;
	var.head = NULL;
	var.fd = fd;
	var.buffer = NULL;
}

/**
 * input - checks if file can be opened
 * @argc: number of arguments passed to th eprogram
 * @argv: argument vector
 * Return: file
 */

FILE *input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - entry point into the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int num);
	FILE *file;
	size_t size = 256;
	size_t get_line = 0;
	char *lines[2] = {NULL, NULL};

	file = input(argc, argv);
	start_var(file);
	get_line = getline(&var.buffer, &size, file);

	while (get_line != -1)
	{
		lines[0] = strtok(var.buffer, "\t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", var.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				exit(EXIT_FAILURE);
			}
			var.arg = strtok(NULL, " \t\n");
			f(&var.head, var.cont);
		}
		get_line = getline(&var.buffer, &size, file);
		var.cont++;
	}
	return (0);
}
