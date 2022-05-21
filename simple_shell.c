#include "main.h"

/**
 * main - simple shell
 * @argc: number of arguments
 * @argv: list of command line arguments
 * @env: environment variable
 * Return: Always 0, -1 on error.
 */
int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    char *token;
    char **tokens = malloc(256 * sizeof(char));
    int i = 0;
    char *search = " ";

    if (argc >= 2)
    {
        if (execve(argv[1], argv, NULL) == -1)
        {
            perror("Error:");
        }
    }
    else
    {
        while (1)
        {
            prompt("#cisfun$ ");
            if((getline(&line, &len, stdin)) != -1)
            {
                line[_strlen(line) - 1] = '\0';
                token = strtok(line, search);
                while (token != NULL)
                {
                    tokens[i] = token;
                    token = strtok(NULL, search);
                    if (token == NULL)
                    {
                        break;
                    }
                    i++;
                    tokens[i] = token;
                }
                tokens[i + 1] = NULL;
                exec(tokens,env);
            }
            else
            {
                return (1);
            }
        }
    }
    return (0);
}
