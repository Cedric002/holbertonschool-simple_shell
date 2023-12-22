#include "main.h"

/**
 * main - simple shell project launcher
 * @ac: number of argument passed at launch
 * @argv: arguments array (NULL terminated) of arguments
 * Return: (0) at success or (1) on faillure
 */
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **argv)
{
	char **arg_vect = NULL, *exec_name;
	pid_t child = 0;
	int wstatus;

	if (ac > 1)
	{
		exec_name = _get_executable_path(*(argv + 1));
		if (exec_name != NULL)
		{
			child = fork();
			if (child == -1)
				exit(EXIT_FAILURE);
			if (child == 0)
			{
				if (execve(exec_name, (argv + 1), NULL) == -1)
					exit(EXIT_FAILURE);
			}
			else
				waitpid(child, &wstatus, 0);
		}
	}
	if (!isatty(fileno(stdin)))
		_execpipe();

	while (1)
	{
		
		arg_vect = _prompt("$ ");
		_execve((const char **) arg_vect);
		clearerr(stdin);
		continue;
	}
	return (0);
}
