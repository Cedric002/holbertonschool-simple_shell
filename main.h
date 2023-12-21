#ifndef SIMPLE_SHELL_
#define SIMPLE_SHELL_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>

extern char **environ;

void printStrings(const char **array_of_strings);
char **_get_argv(const char *str, const char *delimiter);
char *_getenv(const char *name);
char *get_exec_name(char *name);
char *_get_excutable_name_argv(const char **);
char *_get_excutable_name_str(const char *);
int _execve(const char **argv);
char *_get_executable_path(const char *name);
void _free_arr(char ***str_arr);
void _free(char **str);

#endif
