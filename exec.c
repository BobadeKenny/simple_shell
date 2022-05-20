#include "main.h"

/**
 * exec - executes commands
 * @tokens: commands
 * @env: environment variables
 * Return: Always 0, -1 on error.
 */
int exec (char **tokens, char **argv, char **env)
{
    pid_t child_pid;
    int status;
    unsigned int i;
    char *arg;

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
      arg = tokens[1];
      if (!tokens[1])
        arg = NULL;
      return (changedir(arg));
    }
    if (strncmp("exit", tokens[0], 4) == 0)
    {
      if (tokens[1])
      {
        exit(atoi(tokens[1]));
      }
      else
      {
		    exit(0);
      }
    }
 child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(tokens[0], argv, environ) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);
    return (0);
}
