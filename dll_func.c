#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_end - adds a node at the end of a dll
 * @head: double pointer to the head of the dll
 * @data: data element tobe added
 * Return: addres of the new node
 */
stack_t add_end(stack_t **head, const int n)
{
	stack_t *newNode, *temp;

	newNode = (stack_t*)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		perror("Error: malloc failed\n");
		free(newNode);
		exit(EXIT_FAILURE);
	}
	newNode->n = n;

	if ((*head) == NULL)
	{
		newNode->next = (*head);
		newNode->prev = NULL;
		(*head) = newNode;
		return (*newNode);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next = newNode;
	return (*newNode);
}

/**
 * add_beginning - adds a new node at the beginning of a dll
 * @head: pointer to the head of the list
 * @n: data element to be added
 * Return: address of the new node
 */

stack_t add_beginning(stack_t **head, const int n)
{
	stack_t *newNode;

	newNode = (stack_t*)malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		perror("Error: malloc failed\n");
		free(newNode);
		exit(EXIT_FAILURE);
	}
	newNode->n = n;
	if (*head == NULL)
	{
		newNode->prev = NULL;
		newNode->next = (*head);
		(*head) = newNode;
		return (*newNode);
	}
	(*head)->prev = newNode;
	newNode->next = (*head);
	newNode->prev = NULL;
	(*head) = newNode;

	return (*newNode);
}
/**
 * free_list - frees a dll
 * @head: double pointer to the hed of the list
 * Return: nothing
 */

void free_list(stack_t **head)
{
	stack_t *temp;

	while ((*head) != NULL)
	{
		temp = (*head);
		*head = (*head)->next;
		free(temp);
	}
}
