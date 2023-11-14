#include "alx.h"
/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * @env: enviroment variable
 * Return: 0
 */

int main(int __attribute__((unused))argc, char **argv, char **env)
{
	int status_output = 0, in_put = 1, counter = 0;

	while (in_put)
	{
		char *c_line = NULL, **argm = NULL;
		size_t l_s = 0;/*line size*/

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		signal(SIGINT, signal_ignore);
		in_put = getline(&c_line, &l_s, stdin);
		if (in_put < 0)
		{
			free(c_line);
			exit(status_output);
		}
		if (in_put == 1)
		{
			free(c_line);
			continue;
		}
		if (in_put != EOF)
		{
			counter++;
			_strtok(c_line, "\n");
			if (_myexit(c_line) == 0)
				return (status_output);
			if (_myenv(c_line, counter, argv, env) == 0)
				continue;
			argm = splitline(c_line);
			if (argm[0] == NULL)
			{
				free(c_line), free(argm);
				continue;
			}
			status_output = execute_process(argm, argv, counter);
		}
		free(c_line), free(argm);
	}
	return (status_output);
}
