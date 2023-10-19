#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* list_funcs1.c */
size_t thelistint_len(const listint_t *h);
listint_t *adding_nodeint(listint_t **head, const int n);
size_t printing_thelistint(const listint_t *h);
int del_node_atindex(listint_t **head, unsigned int index);
listint_t *get_node_atindex(listint_t *head, unsigned int index);

/* list_funcs2.c */
listint_t *push_node_atindex(listint_t **h, unsigned int idx, int n);
listint_t *adding_nodeint_end(listint_t **head, const int n);
void freeing_thelists(listint_t *head);

#endif
