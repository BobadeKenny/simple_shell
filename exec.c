#include "main.h"

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
            prompt(environ[i]);
            prompt("\n");
            i++;
        }
        return (0);
        
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
    if (child_pid == 0)
    {
        if (execve(tokens[0], tokens, NULL) == -1)
        {
            perror("Error");
        }
    }
    else
    {
        wait(&status);
    }
    return (0);
}