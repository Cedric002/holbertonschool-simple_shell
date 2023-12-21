#include "main.h"

/**
 * _execve - function that execute a line of command
 * @argv: command arguments vect
 * Return: (1) success and (0) faillure
 */
int _execve(const char **argv)
{
	pid_t child_pid;
	int wstatus, exit_status;
	char *exec_path = NULL;

	if  (argv != NULL && argv[0] != NULL)
	{
		exec_path = _get_executable_path(argv[0]);
		if (exec_path != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
				exit(EXIT_FAILURE);

			if (child_pid == 0)
			{
				if (execve(exec_path, (char *const *) argv, NULL) == -1)
				{
					fprintf(stderr, "%s : failed\n", argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(child_pid, &wstatus, 0);
				if (wstatus)
				{
					exit_status = WEXITSTATUS(wstatus);
					if (exit_status == EXIT_FAILURE)
						return (EXIT_FAILURE);
				}
			}
		}
		else
		{
			fprintf(stderr, "%s : command can't be found!\n", argv[0]);
			return (0);
		}
	}
	return (1);
}
