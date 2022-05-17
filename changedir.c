#include "main.h"

int changedir(char *arg)
{
  /*  char *curdir;
    char *path;
    char *lastdir;*/

    if (arg == NULL)
    {
        arg = getenv("HOME");
    }
    if (chdir(arg))
    {
        perror("Error");
		return (1);
    }
    return (0);
}