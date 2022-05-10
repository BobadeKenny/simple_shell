#include "main.h"

int exec (char **tokens)
{
    pid_t child_pid;
    int status;
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