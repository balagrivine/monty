#include "monty.h"

/**
 * _queue - sets the format of the data to a queue
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _queue(stack_t **head, unsigned int num)
{
	(void)(*head);
	(void)num;

	var.lifo = 0;
}

/**
 * _stack - sets the format of the data to a stack
 * @head: double pointer to the head of the list
 * @num: line count
 * Return: nothing
 */

void _stack(stack_t **head, unsigned int num)
{
	(void)(*head);
	(void)num;

	var.lifo = 1;
}

/**
 * _add - adds the top two elementsof the stack
 * @head: double pointer to the head of the stack
 * @num: line count
 * Return: nothing
 */

void _add(stack_t **head, unsigned int num)
{
	int i;
	stack_t *temp;

	temp = *head;
	for (i = 0; temp != NULL; i++)
	{
		temp = temp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n += (*head)->n;
	_pop(head, num);
}

/**
 * _nop - does nothing
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _nop(stack_t **head, unsigned int num)
{
	(void)(*head);
	(void)num;
}

/**
 * _sub - subtracts top two elements of the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _sub(stack_t **head, unsigned int num)
{
	int i;
	stack_t *temp;

	temp = *head;
	for (i = 0; temp != NULL; i++)
	{
		temp = temp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n");
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n = (*head)->n;
	_pop(head, num);
}
