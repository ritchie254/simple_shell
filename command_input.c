#include "alx.h"

/**
 * get_char - gets input from the user
 * Return: command line or EOF(end of file).
 */
int get_char(void)
{
	static unsigned char buffer[BUFF_SIZE];
	static int index;
	static int counts;

	index = 0;
	counts = 0;
	if (index >= counts)
	{
		index = 0;
		counts = read(STDIN_FILENO, buffer, BUFF_SIZE);
		printf("%i\n", counts);
		if (counts == 0)
			return (EOF);
		if (counts < 0)
			return (EOF);
	}
	return (buffer[index++]);
}
