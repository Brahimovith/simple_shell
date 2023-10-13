#include "shell.h"

/**
* _getline - take line from user
*
* Return: string
*/
char *_getline(void)
{
	char *line = NULL;
	size_t size;
	int c, i;

	size = 0;
	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (1)
	{
		c = line[i];
		if (c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (line);
}
