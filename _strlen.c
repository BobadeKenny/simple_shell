#include "main.h"
/**
 * _strlen - find length of string
 * @str: string
 * Return: num of chars in str
*/
int _strlen(const char *str)
{
int i = 0;
while (str[i])
	i++;

return (i);
}
