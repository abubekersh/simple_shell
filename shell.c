#include <stdio.h>
#include <unistd.h>

/**
 * main - entry point of the program
 * Return: int
 */
int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("the id of this proccess is %u\n", pid);
	return (0);
}
