#include "hshell.h"

/**
 *main - entry point
 * @ac: argument count
 * @av: arguement vector
 * @env: environment variable
 * Return: 0 if successful
 */

int main(int ac, char **av, char **env)
{
	char *usr_input = NULL, *cmd[32], *cmd_path = NULL;
	ssize_t num_read = 1;
	size_t n = 0;
	int i, flag, path_value, cmd_count = 0, ret = 0, file_in_flag = 1;
	(void) ac;


	while (num_read != EOF && file_in_flag)
	{
		if (isatty(STDIN_FILENO))
			_puts("Ojashell$ ");
		if (av[1] != NULL)
		{
			usr_input = _strdup(av[1]);
			file_in_flag = 0;
		}
		else	
			signal(SIGINT, _ControlC), num_read = getline(&usr_input, &n, stdin);
		if (num_read == EOF)
		{
			free(usr_input);
			return (ret);
		}
		cmd_count++;
		del_newline(usr_input);
		if (usr_input[0])
		{
			cmd[0] = _strtok(usr_input, " ");
			for (i = 1, flag = 1; flag; i++)
			{
				cmd[i] = _strtok(NULL, " ");
				if (cmd[i] == NULL)
					flag = 0;
			}
			cmd_path = get_path(cmd[0], env, &path_value);
			ret = switcher(path_value, cmd_path, cmd,
					env, av, cmd_count, usr_input, ret);
			free(cmd_path);
			if (av[1] != NULL)
				free(usr_input);
		}
	}
	return (ret);
}
