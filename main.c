#include "hshell.h"

/**
 *prompt - prints out prompt
 *Return: Nothing
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		_puts("Ojashell$ ");
}

/**
 * _ControlC - block signal of Ctrl + C
 * @s: signal to verify
 * Return: Nothing.
 */

void _ControlC(int s)
{
	(void)s;

	write(STDOUT_FILENO, "\nOjashell$ ", 11);
}
/**
 *main - entry point
 * @ac: argument count
 * @av: arguement vector
 * @env: environment variable
 * Return: 0 if successful
 */

int main(__attribute__((unused))int ac, char **av, char **env)
{
	char *usr_input = NULL, *cmd[32], *cmd_path = NULL;
	ssize_t getret = 1;
	size_t n = 0;
	int i, flag, pathval, cmd_count = 0, ret = 0, check = 1;

	while (getret != EOF && check)
	{
		prompt();
		if (av[1] != NULL)
		{
			usr_input = _strdup(av[1]);
			check = 0;
		}
		else
			signal(SIGINT, _ControlC), getret = getline(&usr_input, &n, stdin);
		if (getret == EOF)
		{
			free(usr_input);
			return (0);
		}
		cmd_count++;
		check_stuff(usr_input);
		if (usr_input[0])
		{
			cmd[0] = _strtok(usr_input, " ");
			for (i = 1, flag = 1; flag; i++)
			{
				cmd[i] = _strtok(NULL, " ");
				if (cmd[i] == NULL)
					flag = 0;
			}
			cmd_path = find_path(cmd[0], env, &pathval);
			ret = switcher(pathval, cmd_path, cmd,
					env, av, cmd_count, usr_input, ret);
			free(cmd_path);
			if (av[1] != NULL)
				free(usr_input);
		}
	}
	return (ret);
}
