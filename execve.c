/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:42:23 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/07 18:18:35 by dvargas          ###   ########.fr       */
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

/*
int access(int argc, char **argv, char **envp)
{
	char **matrix;
	char *cmd;

	char *argvec[] = {argv[1], NULL};



	int i = 0;
	while(envp[i] != NULL) //
	{
		if(ft_strncmp("PATH=", envp[i], 5) == 0)
			matrix = ft_split(envp[i], ':');
		i++;
	}
	i= 0;
	while(matrix[i] != NULL)
	{
		char *path = ft_strjoin(matrix[i], "/");
		path = ft_strjoin(path, argv[1]);
	//	printf("%s \n", path);
		if(access(path, X_OK | F_OK) == 0 ) // X_OK (SE PODE SER EXECUTADO) 'E' F_OK(SE EXISTE)
			cmd = path;
		//return path;
		i++;
	}
//	printf("%s", cmd);
	executable(cmd, argvec, NULL);
}
*/
