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
int exec (char **tokens, char **env);
void findPath(char **tokens);
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
int changedir(char *arg);

#endif
