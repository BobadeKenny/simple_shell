#include "main.h"

void findPath(char **tokens)
{
    char **paths = malloc(1024 * sizeof(char));
    char *PATH = getenv("PATH");
    char *search = ":";
    char *currentPath;
    int i = 0;
    struct stat st;
    int j = 0;
    char *buffer = NULL;


    currentPath = strtok(PATH, search);
    while (currentPath != NULL)
    {
        paths[i] = currentPath;
        currentPath = strtok(NULL, search);
        i++;
    }
    paths[i] = NULL;
    while (paths[j])
    {
        buffer = strcat(strcat(paths[j], "/"), tokens[0]);
        printf("%s:", buffer);
        if (stat(buffer, &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        j++;
    }
}