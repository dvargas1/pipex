#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

char *yellowbrickroad(char *cmd, char **matrix);
void reaper(char *cmd, char **envp);
void pipex(int argc, char **argv, char **envp);
void ft_process(char *argv, char **envp);
void pipex(int argc, char **argv, char **envp);

#endif
