#include "main.h"

/**
 * _printenv - function that print env variables
 * Return: nothing
 */
void _printenv(void)
{
	size_t loop_counter = 0;

	if (environ != NULL)
	{
		while (*(environ + loop_counter) != NULL)
		{
			printf("%s\n", *(environ + loop_counter));
			loop_counter++;
		}
	}
}
