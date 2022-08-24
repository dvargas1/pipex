/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:40 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/24 20:23:25 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(char *argv, char **envp)
{
	int	pid;
	int	pipes[2];

	if (pipe(pipes) == -1)
		perror("ERROR IN PIPES");
	pid = fork();
	if (pid == -1)
		perror("ERROR IN PID");
	if (pid == 0)
	{
		close(pipes[1]);
		dup2(pipes[0], 0);
	}
	if (pid > 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		reaper(argv, envp);
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	int	file_in;
	int	file_out;
	int	i;

	i = 3;
	file_in = open(argv[1], O_RDONLY);
	if (file_out == -1)
	{
		perror("ERROR WITH FILE1");
		exit(127);
	}
	file_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		perror("ERROR WITH FILE2");
	dup2(file_in, 0);
	dup2(file_out, 1);
	ft_process(argv[2], envp);
	reaper(argv[i], envp);
	close(file_in);
	close(file_out);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 5)
	{
		pipex (argc, argv, envp);
		return (0);
	}
	else
	{
		perror("we need 4 arguments");
		exit (1);
	}
}
