#include "main.h"

/**
 * _free - free a string
 * @str: string to free
 * Return: nothing
 */
void _free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

/**
 * _free_arr - frees array of string
 * @str_arr: array of str
 * Return: nothing
 */
void _free_arr(char ***str_arr)
{
	size_t loop_counter = 0;

	if (str_arr != NULL && *str_arr != NULL)
	{
		while ((*str_arr  + loop_counter) != NULL &&
				*(*str_arr + loop_counter) != NULL)
		{
			free(*(*str_arr + loop_counter));
			loop_counter++;
		}
		free(*str_arr);
		*str_arr = NULL;
	}
}
