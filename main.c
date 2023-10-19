#define _POSIX_C_SOURCE 200809L
#include "monty.h"

global_t var;

/**
 * free_var - frees global variables
 * Return: nothing
 */

void free_var(void)
{

	free_list(&var.head);
	free(var.buffer);
	fclose(var.fd);
}
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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
	size_t len = 0;
	char *lines = NULL;
	char *instruct;

	file = input(argc, argv);
	start_var(file);

	while (getline(&lines, &len, file) != -1)
	{
		instruct = strtok(lines, " \t\n");
		if (instruct && instruct[0] != '#')
		{
			f = get_opcode(instruct);
			if (!f)
			{
				fprintf(stderr, "L%u: ", var.cont);
				fprintf(stderr, "unknown instruction %s\n", instruct);
				free_var();
				free(lines);
				exit(EXIT_FAILURE);
			}
			var.arg = strtok(NULL, " \t\n");
			f(&var.head, var.cont);
		}
		var.cont++;
	}
	free_var();
	free(lines);
	return (0);
}
