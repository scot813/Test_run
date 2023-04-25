#include "shell.h"
/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * @env: the environment
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
