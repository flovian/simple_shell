#include "main.h"

/**
 * get_built - checks if input is a built-in command and if so
 * executes its associated function
 * @input_list: list representing input command
 * @shell_name: name of shell program
 * @env_list: list of environment variables
 *
 * Return: integer, -1 if built-in does not exist
 */
int get_built(list_t *input_list, char *shell_name, list_t *env_list)
{
	char *name;
	int i;

	built_s built_ins[] = {
		{"exit", exit_shell},
		{"env", env_func},
		{"setenv", setenv_func},
		{"unsetenv", unsetenv_func},
		{NULL, NULL}
	};

	name = input_list->name;

	for (i = 0; built_ins[i].name; i++)
	{
		if (_strcmp(name, built_ins[i].name) == 0)
			return (built_ins[i].f(input_list, shell_name, &env_list));
	}

	return (-1);
}
/**
 * exit_shell - implements the exit built-in functionality
 * @input_list: list of command and arguments
 * @shell_name: name of shell program
 * @env_list_ptr: pointer to list of environment variables
 *
 * Return: exit code. Otherwise -2
 */
int exit_shell(list_t *input_list, char *shell_name, list_t **env_list_ptr)
{
	int num;

	if (input_list->next == NULL)
		return (0);

	num = _atoi(input_list->next->name);

	if (num == -1)
	{
		print_error(shell_name, "Invalid exit status\n");
		return (-2);
	}

	(void)env_list_ptr;
	return (num);
}