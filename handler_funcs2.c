#include "monty.h"
#include "lists.h"

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void sub_handler(stack_t **stack, unsigned int ln_number)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, sub);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void div_handler(stack_t **stack, unsigned int ln_number)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, div);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int ln_number)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, mul);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @ln_number: number of the line in the file
 */
void mod_handler(stack_t **stack, unsigned int ln_number)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_node_atindex(*stack, 0);
	stack_t *node_1 = get_node_atindex(*stack, 1);

	if (thelistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, ln_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	del_node_atindex(stack, 0);
	del_node_atindex(stack, 0);
	node = adding_nodeint(stack, mod);
	if (!node)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
