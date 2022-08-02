/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvargas <dvargas@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 22:48:40 by dvargas           #+#    #+#             */
/*   Updated: 2022/08/02 08:40:35 by dvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

./pipex[0] infile[1] cmd1[2] cmd2[3] file2[4]

//pipe[0] READ
//pipe[1] WRITE

int main (int argc char **argv **envp)
{
	int fd[2];
	int pipe[2];

	pipe(pipe);

	// PRIMEIRO CONSTRUIMOS OS DOIS PROCESSOS E MIRAMOS O STDIN (0) E STDOUT(1) PARA ONDE PRECISAMOS.
	int pid1 = fork();
	if (pid1 == 0)
	{
		fd[0] = open(argv[1]); // fd[0] é o primeiro arquivo, observar parametros de OPEN e FIFO da função
		dup2(fd[0], 0); // 0 A informação será lida daqui
		dup2(pipe[1], 1); // 1 Envia informação será passada por meio deste pipe
		close(pipe[0]);
		close(fd[1]);
		//Encontre o comando no sistema e execute, aqui agnt deve usar execv
	}
	else
		waitpid(pid1);

	int pid2 = fork();
	if (pid2 == 0)
	{
		fd[1] = open(argv[4]) // fd[1] é o arquivo FIM, observar parametros OPEN e FIFO eles de vem ser alterados conforme necessidade de criação do arquivo/apend no arquivo
		dup2(fd[1], 1); // A informação será escrita nesse arquivo fd[i], ele que será executado no comando Open, por isso a atenção nos parametros de OPEN.
		dup2(pipe[0], 0); // Receptor da informação do pipe[1]
		close(pipe[1]);
		close(fd[0]);
	//Encontre o comando no sistema e execute.
	}
	else
		waitpid(pid2);
	return (0);
}


/*
----------------------------DESCRICAO-----------------------------------------
O programa deve se comportar como

$ < file1 cmd | cmd2 > file2

Ele será chamado dessa forma:

$ ./pipex infile "ls -l" "wc -l" outfile

@@@@@@ BONUS @@@@@@@

Fazer o comando lidar com multiplos processos 
$ < file1 cmd1 | cmd2 | cmd3 | cmd4 | cmd5 > file2

será chamado dessa forma

$ ./ file1 cmd1 cmd2 cmd3 cmd4 cmd5 file2

O arquivo tbm tem que suportar >> e << quando o primeirp parametro estiver em aspas duplas

$. << LIMITER | cmd1 >> file

será chamdo dessa forma

$ ./pipex here_doc LIMITER cmd cmd1 file
-------------------------------------------------------------------------------

Conceitos Básicos

Shell funciona com standard input e output 
Standard input são os dados necessários para o programa funcionar
Standard output são os dados queo programa processou 

O shell permite que voce redirecione o std input e output utilizando ">" e "<" da seguinte maneira.

$ cat < fileA (estou indicando que farei o uso do comando "CAT" no arquivo fileA

$ cat < fileA > fileB (fazer o comando "CAT" no arquivo fileA e enviar o resultado desse comando para o arquivo fileB) OBS: se ele nao for utilizado o resultado sera enviado para STDOUT que é o tty (terminal)

os comandos ">>" e "<<" fazem basicamente a mesma coisa que suas versões únicas, a diferençaa aqui é que ele não deleta o conteúo anterior do arquivo, mas sim atualiza com novos dados.

Pipe "|" permite que conectemos o STDOUT de um comando com um STDIN de outro 
fazendo conseguindo uma ligação entre eles para que o conteúdo de um possa ser utilizado
pelo outro.
Exemplo:.

$fileA < fileA cat | wc -l (aqui ele vai ser a fileA, utlizar o comando cat, depois wc -l e retornar ao STDOUT, se for colocado um > no final ele retorna esse valor para o arquivo que for encaminhado.

Processo é a forma de representar um programa em execução , é esse processo que utiliza os recuros disponibilizados pelo computador, memoria e processador por exemplo.

-------------------------------------------------------------------------------
Funções permitidas

open, close, read, write, malloc, free - Essas são velhas conhecidas

perror - void perror(cons char *str)
printa uma mensagem descritiva de erro para o "stderr", "str" é impresso seguido de uma virgual e espaço

strerror - char *strerror (int errnum)
procura uma array interna com o número do erro "errnum" e retorna um ponteiro para essa mensagem.

access - int access(const char *pathname, int mode)
checa se o processo evocador consegue acessar o "pathname"
Exemplo, o utilizador nao tem permissões para acessar um arquivo, retorna -1 caso sucesso o retorno é 0

dup - int dup(int oldfd)
cria uma cópia de um file descriptor, ele utiliza sempre o menor número disponível de fd disponivel para ser o número de descritor.

dup2- int dup2(int oldfd, int newfd)
cria uma copia de um file descriptor mas aqui escolhemos o numero do descritor.

execve- int execve(const char *pathname, char *const argv[], char *const envp[])
encarregado de executar o programa referenciado no pathname.

exit-void exit(int status)
finaliza o processo imediatamente, qualquer file descriptor aberto pelo processo também é finalizado.

fork- fork()
fork é usado para criar um novo processo, este chamado de "child process" que roda ao mesmo tempo do "parent process" depois que um "child" é criado os dois processos executam as proximas instruções que seguem o chamado de fork() Esse comando retorna 0 se tudo correr bem e -1 se tiver algum probleama, podendo ser atribuido a uma variável como int id = fork();  

pipe-
cria uma estrutura que permite alterar o STDIN e OUT de um processo, é por meio dele que faremos todo nosso codigo

unlink- 

wait- wait()
Tem é usado para avisar ao compilador que aquele processo em especifico, um parent
ou um child terá que esperar o outro finalizar a instrução para ele seguir e fazer a mesma. de certeza forma, essa funcao organiza os processos dentro do codigo.

waitpid-
Consegue enviar a informação de qual processo quero esperar, e se preciso esperar um status específico do processo para continuar a impressão

*/
