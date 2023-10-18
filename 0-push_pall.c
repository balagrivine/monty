#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - pushes an element to the stack
 * @head: pointer to the head of the doubly lunked list
 * @num: line number
 * Return: nothing
 */

void _push(stack_t **head, unsigned int num)
{
	int i, j;

	if (var.arg == NULL)
	{
		drpintf(2, "L%u: ", num);
		dprintf(2, "usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; var.arg[i] != '\0'; i++)
	{
		if (!isdigit(var.arg[i]) && var.arg[i] != '-')
		{
			dprintf(2, "L%u: ", num);
			dprintf(2, "usage: push integer\n");
			exit(EXIT_FAILURE);
		}
	}
	j = atoi(var.arg);

	if (var.lifo == 1)
	{
		add_beginning(head, j);
	}
	else
		add_end(head, j);
}

/**
 * _pall - prints all the vales of a stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _pall(stack_t **head, unsigned int num)
{
	stack_t *temp;
	(void)num;

	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _pint(stack_t **head, unsigned int num)
{

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", num);
		dprintf(2, "can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element of the stack
 * @head: double pointer to the head f the list
 *
 * @num: line number
 * return: nothing
 */

void _pop(stack_t **head, unsigned int num)
{
	stack_t *temp;

	if (*head == NULL)
	{
		dprintf("L%u: ", num);
		dprintf(2, "can't pop an emppty stack\n");
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * _swap - swaps the top two elements of the  stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _swap(stack_t **head, unsigned int num)
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
		dprintf(2, "L%u: can't swap, stack too short", num);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = (*head);
	(*head)->next = temp;
	(*head)->prev = NULL;
}
