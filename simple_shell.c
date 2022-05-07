#include "main.h"

int main()
{
    char c = '$';
    char s = ' ';
    size_t buffersize = 32;
    char *buffer;
    size_t cmd;

    do 
    {
        write(1, &c, 1);
        write(1, &s, 1);
        cmd = getline(&buffer, &buffersize, stdin);
        printf("%u is",cmd);
        printf("%s",buffer);
    }
    while (arg);
    return (0);
}