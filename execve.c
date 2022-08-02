/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:42:23 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/02 10:11:39 by dvargas          ###   ########.fr       */
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

int main (char **envp){

	char *cmd = "/usr/bin/ls";

	char *argvec[] = {"ls", "-l", NULL};
	char *envvec[] = {"NULL"} ;

	printf("teste1234");

	executable(cmd, argvec, envvec);


}

