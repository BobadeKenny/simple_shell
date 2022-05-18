#include "main.h"

char lastdir[PATH_MAX];
int changedir(char *arg)
{
    char curdir[PATH_MAX];

    if (getcwd(curdir, sizeof(curdir)))
    {
        *curdir = '\0';
    }
    if (arg == NULL)
    {
        arg = getenv("HOME");
    }
    if (strncmp("-", arg, 1) == 0)
    {
        if (*lastdir == '\0')
        {
            perror("Error");
		    return (1);
        }
        arg = lastdir;
    }
    if (chdir(arg))
    {
        perror("Error");
		return (1);
    }
    strcpy(lastdir, curdir);
    return (0);
}