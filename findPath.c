#include "main.h"

/**
 * findPath - find program in path
 * @tokens: commands
 * Return: none
 */
int findPath(char **args)
{
	char *pathenv, *token,  *path;
	int  check_run = 0;
	struct stat st;

	pathenv = getenv("PATH");
	pathenv = strdup(pathenv);
	token = strtok(pathenv, ":");
	while (token != NULL)
	{
		path = strcat(token, args[0]);
		printf("%s:\n", path);
		if (stat(path, &st) == 0)
		{
			args[0] = path;
			if (access(args[0], X_OK) == 0)
			{
				printf("%s:", args[0]);
				printf(" FOUND\n");
			}
			else
			{
				printf("%s:", args[0]);
				printf(" NOT FOUND\n");
				write(STDERR_FILENO, ": permission denied", 19);
				free(path);
			}
			check_run++;
			break;
		}
		free(path);
		token = strtok(NULL, ":");
	}
    return(1);
}
