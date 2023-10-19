#include "monty.h"
#include "lists.h"

/**
 * push_node_atindex - insert a node in index
 * @h:  pointer to  list
 * @idx: inserted node index
 * @n: data to be inserted
 * Return: address or NULL in failed
 */
listint_t *push_node_atindex(listint_t **h, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *h;

	if (idx == 0)
		return (adding_nodeint(h, n));

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (adding_nodeint_end(h, n));
			new = malloc(sizeof(listint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * adding_nodeint_end - adding nodes in double linked list
 * @head: pointer of list
 * @n: new node data
 * Return: the address of node or NULL
 */
listint_t *adding_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * freeing_thelists - freeing  linked list
 * @head: pointer of  free list
 */
void freeing_thelists(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
