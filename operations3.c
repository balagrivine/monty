#include "monty.h"

/**
 * _rot1 - rotates the first eleemnt to the bottom and the second to the top
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _rot1(stack_t **head, unsigned int num)
{
	stack_t *temp1, *temp2;
	(void)num;

	temp1 = NULL;
	temp2 = NULL;

	if (*head == NULL)
	{
		return;
	}
	if ((*head)->next == NULL)
	{
		return;
	}
	temp1 = (*head)->next;
	temp2 = *head;

	for (; temp2->next; temp2 = temp2->next)
		;

	temp1->prev = NULL;
	temp2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp2;
	*head = temp1;
}

/**
 * _rotr - reverses the stack
 * @head: double pointer to the head of the list
 * @num: line number
 * Return: nothing
 */

void _rotr(stack_t **head, unsigned int num)
{
	stack_t *temp;
	(void)num;

	temp = NULL;

	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
		return;

	temp = *head;
	for (; temp->next; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *head;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}
