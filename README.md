# Pipex :cloud_with_lightning_and_rain:	

This project we need to create a program that handles pipes, it must run with 4 arguments for the mandatory part and it must have the same behavior as:

``
 < file1 cmd1 | cmd2 > file2
``

Your program will be executed as follows:

``
./pipex file1 cmd1 cmd2 file2
``

Example:
``
./pipex file1 ls wc file2
``

File2 should contain the result of the "ls" command processed by the "wc" command

## Program Prototype

It's the first time we're creating a program, so we don't need to follow a specific porototyping of a function.

But I was sad to make such a cool program called pipex and not have the pipex function!

### Requirements
 - You have to turn in a Makefile which will compile your source files. It must not relink.
 -  You have to handle errors thoroughly. In no way your program should quit unexpectedly (segmentation fault, bus error, double free, and so forth).
 - Your program mustn’t have memory leaks.
 -  If you have any doubt, handle the errors like the shell command

# Bonus Part

For the bonus part we need to handle multiple pipes like in bash.

This:
``
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
``

Should behave like:
``
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
``

It's also a bonus to implement the Here_Doc bash system.

## Grade
115/100
