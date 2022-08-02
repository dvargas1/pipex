/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:42:23 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/02 17:05:34 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// com Execve, chamamos ele com os argumentos, primeiro o Path do comando solicitado
// nesse caso /usr/bin/ls, segundo os parametros que vamos seguir ao chamar o comand
// o primeiro parametro deve ser o nome do comando: ls -l e o terceiro, podemos nele
// chamar alguma variavel de ambiente que precisarmos.
void executable(char *cmd, char **argvec, char **envvec)
{
	 if(execve(cmd,argvec, envvec) == -1)
		 perror("Deu ruim aqui");
	 printf("Algo deu errado");
}

int main (int argc, char **argv, char **envp)
{
	char **matrix;


	int i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			printf("%s \n \n\n\n", envp[i]);
			matrix = ft_split(envp[i], ':');
		}
		i++;
	}
	i= 0;
	while(matrix[i] != NULL)
	{
		char *path = ft_strjoin(matrix[i], "/");
		printf("%s \n", matrix[i]);
		printf("%s \n", path);
		path = ft_strjoin(path, argv[1]);
		printf("%s \n", path);
		i++;
	}
	
	
//	executable(cmd, argvec, envvec);
}

