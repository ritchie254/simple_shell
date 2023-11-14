#include "alx.h"

/**
 * _myexit - exits shell
 * @input: command line
 * Return: 0 on (Success) 1 on (Fail)
 */
int _myexit(char *input)
{
	char *command = "exit";
	int j = 0;
	int length = str_length(input);

	if (length == 4)
	{
		while (command[j])
		{
			if (command[j] != input[j])
				return (1);
			j++;
		}
		free(input);
		return (0);
	}
	return (1);
}

/**
 * signal_ignore - Ignore input signal Ctrl + C
 * @signals: signal
 */
void signal_ignore(int signals)
{
	signal(signals, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_ignore);
}

/**
 * _myenv - environment variables.
 * @input: command line.
 * @counter: number of arguments
 * @argv: entry arguments from main
 * @env: environ variables
 * Return: 0 on succes 1 on fails. 127 if env not found
 */
int _myenv(char *input, int counter, char **argv, char **env)
{
	char *environment = "env";
	int i = 0;
	int length = str_length(input);

	if (length == 3)
	{
		while (environment[i])
		{
			if (environment[i] != input[i])
				return (1);
			i++;
		}
		if (env)
		{
			for (i = 0; env[i] != NULL; i++)
				_printf("%s\n", env[i]);
			free(input);
			return (0);
		}
		else
		{
			_printf("%s: %d: env: not found\n", argv[0], counter);
			return (127);
		}
	}
	return (1);
}
