#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void rotl_handler(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)ln_number;

	if (*stack == NULL)
		return;
	temp = get_node_atindex(*stack, 0);
	num = temp->n;
	del_node_atindex(stack, 0);
	adding_nodeint_end(stack, num);
}

/**
 * rotr_handler - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void rotr_handler(stack_t **stack, unsigned int ln_number)
{
	stack_t *temp = *stack;
	int num = 0, len = thelistint_len(*stack);

	(void)ln_number;

	if (*stack == NULL)
		return;
	temp = get_node_atindex(*stack, len - 1);
	num = temp->n;
	del_node_atindex(stack, len - 1);
	adding_nodeint(stack, num);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void stack_handler(stack_t **stack, unsigned int ln_number)
{
	(void)stack;
	(void)ln_number;
	data.myqflag = 0;
}


/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void queue_handler(stack_t **stack, unsigned int ln_number)
{
	(void)stack;
	(void)ln_number;
	data.myqflag = 1;
}
