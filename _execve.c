#include "main.h"

/**
 * _execve - function that execute a line of command
 * @argv: command arguments vect
 * Return: (1) success and (0) faillure
 */
int _execve(const char **argv)
{
	pid_t child_pid;
	int wstatus;
	char *exec_path = NULL;

	if  (argv != NULL && argv[0] != NULL)
	{
		exec_path = _get_executable_path(argv[0]);
		if (exec_path != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
				exit(EXIT_FAILURE);

			if (child_pid == 0 &&
					execve(exec_path, (char *const *) argv, NULL) == -1)
			{
				_free(&exec_path);
				fprintf(stderr, "%s : failed\n", argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "%s : command can't be found!\n", argv[0]);
			return (EXIT_FAILURE);
		}
	}
	else
		return (EXIT_FAILURE);

	if (child_pid != 0)
		waitpid(child_pid, &wstatus, 0);
	_free(&exec_path);
	return (EXIT_SUCCESS);
}
