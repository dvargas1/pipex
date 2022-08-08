#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

void executable(char *cmd, char**argvec, char **envvec);
char *processwhere(char *cmd, char **envp);
void pipex(char **argv, char **envp);


#endif
