#include "main.h"
/**
 * main - entry point of the program
 * Return: int
 */
int main(void)
{
	char **environ;
	pid_t child;
	int status;
	char input[MAX_LENGTH];
	char *args[ARG_SIZE + 1];
	int i = 0;
	char *tok;

	environ = get_environ();
	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(input, MAX_LENGTH, stdin) == NULL)
			return (-1);
		input[strcspn(input, "\n")] = '\0';
		tok = strtok(input, " ");
		while (tok != NULL && i < ARG_SIZE)
		{
			args[i++] = tok;
			tok = strtok(NULL, " ");
		}
		args[i] = NULL;
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
			wait(&status);
	}
	return (0);
}
