#include "monty.h"

/**
 * thelistint_len - return nodes  number
 * @h: pointer of list
 * Return: the number of nodes
 */
size_t thelistint_len(const listint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * adding_nodeint - adding new node at doubly list beginning
 * @head:  pointer of list
 * @n: inserted data in new node
 * Return: new element address , or NULL in failed
 */
listint_t *adding_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * printing_thelistint - make linked list doubly
 * @h: pointer of list
 * Return: nodes number in list
 */
size_t printing_thelistint(const listint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
 * del_node_atindex - delete nodes in index
 * @head: pointer to list
 * @index: index of delete node
 * Return: 1 if success or -1 if failure
 */
int del_node_atindex(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * get_node_atindex - getting  the nth nodes 
 * @head: pointer of list
 * @index: index of returned node
 * Return: address of node or NULL
 */
listint_t *get_node_atindex(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
