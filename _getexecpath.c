#include "main.h"

/**
 * _get_executable_path - function to get path
 * @name: exec name
 * Return: different path
 */
char *_get_executable_path(const char *name)
{
	char *path;
	char **tokens = NULL;
	char *full_path = NULL;
	int loop_counter = 0;

	if (name == NULL || *name == '\0')
		return (NULL);

	path = _getenv("PATH");
	tokens = _get_argv((const char *) path, ":");

	if (tokens == NULL)
	{
		return (NULL);
	}

	while (tokens[loop_counter] != NULL)
	{
		full_path = malloc(strlen(name) + strlen(tokens[loop_counter]) + 2);
		if (full_path == NULL)
			break;
		sprintf(full_path, "%s/%s", tokens[loop_counter], name);

		if (access(full_path, X_OK) == 0)
			break;

		free(full_path);
		full_path = NULL;
		loop_counter++;
	}
	return (full_path);
}
