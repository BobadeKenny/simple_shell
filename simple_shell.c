#include "main.h"

int main(int argc, char *argv[])
{
int main(void)
{
    pid_t child_pid;
    int status;
    char *line = NULL;
    size_t len = 0;
    ssize_t reading;
    char *token;
    char *tokens[];
    int i = 0;
    char *search = " ";

    prompt("#cisfun$ ");
    while((reading = getline(&line, &len, stdin)) != -1)
    {
        token = strtok(line, search);
        while (token != NULL)
        {
            tokens[i] = token;
            token = strtok(NULL, search);
            i++;
        }
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child_pid == 0)
        {
            if (execve(tokens[0], tokens, NULL) == -1)
            {
                perror("Error:");
            }
        }
        else
        {
            wait(&status);
        }
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
    return (0);
}