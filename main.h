#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#define  MAX_LENGTH 100
#define  ARG_SIZE 10
/**
 * get_environ - function
 * Return: char
 */

char **get_environ(void)
{
	extern char **environ;

	return (environ);
}

#endif
