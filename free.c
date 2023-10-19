#include "monty.h"
#include "lists.h"

/**
 * free_all - custom memory handling function
 * @all: flag to indicate what to free
 */
void free_all(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		all_freeing(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			freeing_thelists(data.stack);
			data.stack = NULL;
		}
		if (data.myfptr)
		{
			fclose(data.myfptr);
			data.myfptr = NULL;
		}
	}
}
