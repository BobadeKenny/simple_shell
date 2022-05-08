#include "main.h"
/**
 * prompt - prints the prompter string
 * @str: pointer to the string to print
 * Return: void
*/

void prompt(char *str)
{
int i = 0;
while (str[i])
{
	write(1, &str[i], 1);
	i++;
}
}
