#include "main.h"

/**
 * _prompt - it demands the user to prompt an frees getlin output
 * @_console_str: a string to show on new line of our console
 * Return: it gives us arguments based on user in put;
 */
char **_prompt(const char *_console_str)
{
	char *user_input = NULL, **arg_vect = NULL;
	size_t str_len = 0;
	ssize_t read_bytes;

	printf("%s ", _console_str);
	fflush(stdout);
	read_bytes = getline(&user_input, &str_len, stdin);
	if (read_bytes == -1)
	{
		if (feof(stdin) != 0)
		{
			printf("\n");
			_free(&user_input);
			exit(EXIT_FAILURE);
		}
		return (NULL);
	}
	else
		*(user_input + read_bytes - 1) = '\0';
	if (*user_input == '\n')
	{
		return (NULL);
	}
	else if (strcmp("exit", user_input) == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (strcmp("env", user_input) == 0)
		_printenv();
	else
		arg_vect = _get_argv((const char *) user_input, " ");
	return (arg_vect);
}
