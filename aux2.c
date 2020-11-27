#include "hshell.h"

/**
 * perror_permission - prints the permission denied error message.
 * @file: the name of the file
 * @caller: the name of the executable file that tried to make the call.
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_permission(char *file, char *caller, int com_count)
{
	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(file);
	perror_string(": Permission denied\n");

	return (126);
}

/**
 * perror_file - prints the no such file or directory error message
 * @file: the name of the file
 * @caller: the name of the executable file that made the call
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_file(char *file, char *caller, int com_count)
{
	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(file);
	perror_string(": not found\n");
	return (127);
}

/**
 * perror_command - prints the command not found error message
 * @caller: the name of the shell's executable
 * @command: the command
 * @com_count: the number of commands in current shell session
 * Return: 0
 */
int perror_command(char *caller, char *command, int com_count)
{
	(void) command;

	perror_string(caller);
	perror_string(": ");
	perror_int(com_count);
	perror_string(": ");
	perror_string(command);
	perror_string(": not found\n");

	return (127);
}

/**
 * perror_int - prints an integer to std error.
 * @n: the integer to be printed.
 * Return: 0 if successful.
 */

int perror_int(int n)
{
	char num;

	if (n / 10 > 0)
		perror_int(n / 10);
	num = n % 10 + '0';
	write(STDERR_FILENO, &num, 1);
	return (0);
}

/**
 * print_int - prints an integer to std out.
 * @n: the integer to be printed.
 * Return: 0 if successful.
 */
int print_int(int n)
{
	char num;

	if (n / 10 > 0)
		print_int(n / 10);
	num = n % 10 + '0';
	write(STDOUT_FILENO, &num, 1);
	return (0);
}
