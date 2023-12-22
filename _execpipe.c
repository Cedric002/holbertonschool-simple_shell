#include "main.h"

/**
 * _execpipe - function
 * Return: nothing
 */
int _execpipe(void)
{
	char *user_input = NULL, **arg_v = NULL, *exec_path = NULL;
	size_t size = 0;
	ssize_t read_bytes = 0;
	pid_t child = 0;
	int wstatus;

	if (!isatty(fileno(stdin)))
	{
		read_bytes = getline(&user_input, &size, stdin);
		if (read_bytes == -1)
			return (EXIT_FAILURE);

		*(user_input + read_bytes - 1) = '\0';
		arg_v = _get_argv((const char *) user_input, " ");
		if (arg_v != NULL && *arg_v != NULL)
		{
			exec_path = _get_executable_path((const char *) *(arg_v + 0));
			if (exec_path != NULL)
			{
				child = fork();
				if (child == -1)
					exit (EXIT_FAILURE);
				if (child == 0)
				{
					if (execve(exec_path, arg_v, NULL) == -1)
					{
						_free(&exec_path);
						_free_arr(&arg_v);
						exit(EXIT_FAILURE);
					}
					else
					{
						_free(&exec_path);
						_free_arr(&arg_v);
						exit(EXIT_SUCCESS);
					}
				}
				else
					waitpid(child, &wstatus, 0);
			}
		}
		_free(&exec_path);
		_free(&user_input);
		_free_arr(&arg_v);
	}
	exit (EXIT_SUCCESS);
}
