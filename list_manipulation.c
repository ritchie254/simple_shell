#include "alx.h"
/**
 * _link - built linked list with directories
 * @a: PATH
 * Return: head
 **/
link_t *_link(char *a)
{
	link_t *head = NULL;
	char *token;

	token = _strtok(a, ":");
	while (token != NULL)
	{
		head = _add_node_at_end(&head, token);
		token = _strtok(NULL, ":");
	}
	return (head);
}
/**
 * _add_node_at_end - add a new string to a node at the end
 * @head: head
 * @n: directories
 * Return: head
 **/
link_t *_add_node_at_end(link_t **head, char *n)
{
	link_t *new_node;
	link_t *last_node = *head;

	new_node = malloc(sizeof(link_t));
	if (new_node == NULL)
		return (NULL);
	new_node->dir = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
	return (*head);
}
/**
 * release_list - frees a list_t list
 * @head: head of a node
 */
void release_list(link_t *head)
{
	link_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

