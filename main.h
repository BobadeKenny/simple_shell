#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(char *str);
int exec (char **tokens, char **env);

#endif