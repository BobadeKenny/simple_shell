#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

void prompt(char *str);
int exec (char **tokens, char **argv, char **env);
int findPath(char **tokens);
int _strlen(const char *str);
char *str_addChar (char *str, char c);
char **_strtok(char *str);
unsigned int nbr_spaces(char *s);
char *_strcpy(char *dest, char *src);
int changedir(char *arg);

#endif
