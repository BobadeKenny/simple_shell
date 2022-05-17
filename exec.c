#include "main.h"

/**
 * exec - executes commands
 * @tokens: commands
 * @env: environment variables
 * Return: Always 0, -1 on error.
 */
int exec (char **tokens, char **env)
{
    pid_t child_pid;
    int status;
    unsigned int i;

    if (strncmp("env", tokens[0], 3) == 0)
    {
        i = 0;
        while (env[i] != NULL)
        {
            prompt(env[i]);
            prompt("\n");
            i++;
        }
        return (0);

    }
    if (strncmp("cd", tokens[0], 2) == 0)
    {
      return (changedir(tokens[1]));
    }
    if (strncmp("exit", tokens[0], 4) == 0)
    {
		exit(0);
    }
 child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);
    return (0);
}
