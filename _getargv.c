#include "main.h"

/**
 * _get_argv - function to retrieve argv in a string
 * @string: command
 * @delimiter: a string value
 * Return: the Arguments vectors
 */
char **_get_argv(const char *string, const char *delimiter)
{
	char **argv;
	char *str, *token;
	int loop_counter = 0, segments = 1;

	if (string == NULL || *string == '\0')
		return (NULL);
	str = strdup(string);
	if (str == NULL)
		return (NULL);
	while (str[loop_counter] != '\0')
	{
		if (str[loop_counter] == *delimiter && str[loop_counter + 1] != *delimiter
				&& str[loop_counter + 1] != '\n')
		{
			segments++;
		}
		loop_counter++;
	}
	argv = malloc(sizeof(char *) * (segments + 1));
	if (argv == NULL)
	{
		return (NULL);
	}
	token = strtok(str, delimiter);
	loop_counter = 0;
	while (token != NULL && loop_counter < segments)
	{
		argv[loop_counter] = token;
		loop_counter++;
		token = strtok(NULL, delimiter);
	}
	argv[segments] = NULL;
	return (argv);
}
