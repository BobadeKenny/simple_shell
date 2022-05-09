#include "main.h"


int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t reading;
    char *token;
    char **tokens = malloc(256 * sizeof(char));
    int i = 0;
    int j = 0;
    char *search = " ";

    prompt("#cisfun$ ");
    while((reading = getline(&line, &len, stdin)) != -1)
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
        exec(tokens);
        prompt("#cisfun$ ");
    }


    return (0);
}

    /*pid_t my_pid;
    char c = '$';
    char *line = NULL;
    size_t len = 0;
    ssize_t reading;
    char *token;
    char *search = " ";
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    my_pid = getpid();
    write(1, &c, 1);
    while((reading = getline(&line, &len, stdin)) != -1)
    {
        printf("%d \n", reading);
            token = strtok(line, search);
            while (token != NULL)
            {
            printf("%s \n", token);
            token = strtok(NULL, search);
            if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }

            }
    write(1, &c, 1);

    }
    printf("%u\n", my_pid);
   for (i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    printf("%u\n", argc);*/