#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* list_funcs1.c */
size_t dlistint_len(const listint_t *h);
listint_t *add_dnodeint(listint_t **head, const int n);
size_t print_dlistint(const listint_t *h);
int delete_dnodeint_at_index(listint_t **head, unsigned int index);
listint_t *get_dnodeint_at_index(listint_t *head, unsigned int index);

/* list_funcs2.c */
listint_t *insert_dnodeint_at_index(listint_t **h, unsigned int idx, int n);
listint_t *add_dnodeint_end(listint_t **head, const int n);
void free_dlistint(listint_t *head);

#endif
