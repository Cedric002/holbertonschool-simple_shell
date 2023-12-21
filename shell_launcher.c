#include "main.h"

/**
 * main - simple shell project launcher
 * @ac: number of argument passed at launch
 * @argv: arguments array (NULL terminated) of arguments
 * @env: environment variables of process running
 * Return: (0) at success or (1) on faillure
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **argv,
		char **env)
{
	char *user_input = NULL, **arg_vect = NULL;
	size_t str_len = 0, loop_counter = 0;
	ssize_t read_bytes = 0;

	if (ac >= 2)
	{
		_execve((const char **) argv);
		return (0);
	}

	while (1)
	{
		printf("#cisfun$ ");
		read_bytes = getline(&user_input, &str_len, stdin);
		if (read_bytes == -1)
		{
			if (feof(stdin) != 0)
			{
				printf("\n");
				exit(EXIT_FAILURE);
			}
			continue;
		}
		if (*user_input == '\n')
			continue;

		*(user_input + read_bytes - 1) = '\0';
		if (strcmp("exit", user_input) == 0)
			break;
		else if (strcmp("env", user_input) == 0)
		{
			while ((env + loop_counter) != NULL && *(env + loop_counter) != NULL)
			{
				printf("%s\n", *(env + loop_counter));
				loop_counter++;
			}
			continue;
		}
		arg_vect = _get_argv((const char *) user_input, " ");
		_execve((const char **) arg_vect);
	}
	return (0);
}
