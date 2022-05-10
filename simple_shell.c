#include "main.h"


int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t reading;
    char *token;
    char **tokens = malloc(256 * sizeof(char));
    int i = 0;
    int j = 0;
    char *search = " ";

    if (argc >= 2)
    {
        if (execve(argv[1], argv, NULL) == -1)
        {
            perror("Error:");
        }
        return (1);
    }
    else
    {
        while (1)
        {
            prompt("#cisfun$ ");
            if((reading = getline(&line, &len, stdin)) != -1)
            {
                while (line[j])
                {
                    j++;
                }
                line[j - 1] = '\0';
                token = strtok(line, search);
                while (token != NULL)
                {
                    tokens[i] = token;
                    token = strtok(NULL, search);
                    i++;
                }
                tokens[i] = NULL;
                exec(tokens, env);
            }
            else
            {
                return (1);
            }
        }
    }
    return (0);
}
