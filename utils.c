/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:39:19 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/23 15:53:06 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


char *yellowbrickroad(char *cmd, char **matrix)
{
	char *path;
	int i;

	i = 0;
	if(access(&cmd[0], X_OK | F_OK) == 0)
	{
		path = &cmd[0];
		return(path);
	}
	while(matrix[i] != NULL)
	{
		path = ft_strjoin(matrix[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK | F_OK) == 0)
			return(path);
		i++;
	}
	return(NULL);
}

void reaper(char *cmd, char **envp)
{
	char **matrix;
	char **args;
	char *path;
	int i;

	i = 0;
	args = ft_split(cmd, ' ');
	while(envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			matrix = ft_split(envp[i], ':');
		i++;
	}
	path = yellowbrickroad(args[0],matrix);
	if (execve(path,args,envp) == -1)
	{
		perror("command not founddd");
		exit(127);
	}
}

