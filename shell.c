#include "main.h"
/**
 * main - entry point of the program
 * Return: int
 */

int main(void)
{
	extern char **environ;
	pid_t child;
	int status;
	char input[MAX_LENGTH];
	char *args[2];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, MAX_LENGTH, stdin) == NULL)
		{
			printf("\n");
			return (-1);
		}
		input[strcspn(input, "\n")] = '\0';
		args[0] = input;
		args[1] = NULL;
		child = fork();
		if (child == -1)
		{
			perror("./shell");
			return (-1);
		}
		else if (child == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "execve failed: %s\n", strerror(errno));
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}

	return (0);
}
