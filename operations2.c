#include "monty.h"

/**
 * _div - performs division operation on the top two elements of the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _div(stack_t **head, unsigned int num)
{
	int i;
	stack_t *temp;
	(void)num;

	temp = *head;
	for (i = 0; temp != NULL; i++)
	{
		temp = temp->next;
	}
	if (i < 2)
	{
		perror("L: can't div, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		perror("L: division by zero\n");
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n /= (*head)->n;
	_pop(head, num);
}

/**
 * _mul - multiplies the top two elements of the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */
void _mul(stack_t **head, unsigned int num)
{
	int i;
	stack_t *temp;
	(void)num;

	temp = *head;
	for (i = 0; temp != NULL; i++)
	{
		temp = temp->next;
	}

	if (i < 2)
	{
		perror("L: can't mul, stack too short\n");
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n *= (*head)->n;
	_pop(head, num);
}

/**
 * _mod - performs modulus operation on the top two elementsof the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _mod(stack_t **head, unsigned int num)
{
	int i;
	stack_t *temp;
	(void)num;

	temp = *head;
	for (i = 0; temp != NULL; i++)
	{
		perror("L: can't mod, stack to short\n");
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		perror("L: division by zero\n");
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n %= (*head)->n;
	_pop(head, num);
}

/**
 * _pchar - prints the character value of the first element
 * @head: double pointer to the f=head of the list
 * @num: line number
 * Return: nothing
 */

void _pchar(stack_t **head, unsigned int num)
{
	(void)num;
	if (*head == NULL)
	{
		perror("L: can't pchar, stack empty\n");
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		perror("L: can't pchar, value out of range\n");
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * _pstr - prins the string of the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _pstr(stack_t **head, unsigned int num)
{
	stack_t *temp;
	(void)num;

	temp = *head;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
