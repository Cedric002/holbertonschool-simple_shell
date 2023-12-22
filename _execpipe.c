#include "main.h"

/**
 * _execpipe - function
 * Return: nothing
 */
void _execpipe(void)
{
	char *user_input = NULL, *exec_path = NULL, **arg_v;
	size_t size = 0;
	pid_t child = 0;
	int wstatus;

	if (!isatty(fileno(stdin)))
	{
		if (getline(&user_input, &size, stdin) == -1)
		{
			if (feof(stdin))
				_free(&user_input);
		}
		else
		{
			arg_v = _get_argv((const char *) user_input, " ");
			exec_path = _get_executable_path((const char*) *(arg_v + 0));
			if (exec_path != NULL)
			{
				child = fork();
				if (child == -1)
					exit(EXIT_FAILURE);
				if (child == 0)
				{
					if (execve(exec_path, arg_v, NULL) == -1)
					{
						clearerr(stdin);
						exit(EXIT_FAILURE);
					}
					else
						exit(EXIT_SUCCESS);
				}
				else
				{
					waitpid(child, &wstatus, 0);
					fflush(stdout);
					clearerr(stdin);
					return;
				}
			}
			
		}
	}
}
