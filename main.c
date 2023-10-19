#include "monty.h"
#include "lists.h"

mydata_t data = DATA_INIT;

/**
 * monty - main helper function
 * @args: the pointer to  arg struct 
 * Description: opens reads and call function from the file
 */
void monty(myargs_t *args)
{
	size_t len = 0;
	int get = 0;
	void (*code_func)(stack_t **, unsigned int);

	if (args->ac != 2)
	{
		dprintf(STDERR_FILENO, USAGE);
		exit(EXIT_FAILURE);
	}
	data.myfptr = fopen(args->av, "r");
	if (!data.myfptr)
	{
		dprintf(STDERR_FILENO, FILE_ERROR, args->av);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		args->ln_number++;
		get = getline(&(data.line), &len, data.myfptr);
		if (get < 0)
			break;
		data.words = stringtow(data.line);
		if (data.words[0] == NULL || data.words[0][0] == '#')
		{
			free_all(0);
			continue;
		}
		code_func = get_func(data.words);
		if (!code_func)
		{
			dprintf(STDERR_FILENO, UNKNOWN, args->ln_number, data.words[0]);
			free_all(1);
			exit(EXIT_FAILURE);
		}
		code_func(&(data.stack), args->ln_number);
		free_all(0);
	}
	free_all(1);
}

/**
 * main - the entry point of monty bytecode interpreter
 * @argc: arguments number
 * @argv: arguments array
 * Return: EXIT_SUCCESS in success or EXIT_FAILURE in failed
 */
int main(int argc, char *argv[])
{
	myargs_t args;

	args.av = argv[1];
	args.ac = argc;
	args.ln_number = 0;

	monty(&args);

	return (EXIT_SUCCESS);
}
