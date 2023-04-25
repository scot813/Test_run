#include "shell.h"
/**
 * prompt - entry point
 * @av: argument vector
 * @env: the environment
 * Return: 0
 */
void prompt(char **av, char **env)
{
	int i, j, status;
	char *cmd = NULL;
	ssize_t val;
	size_t n = 0;
	char *argv[N_CMD];
	pid_t firstp;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		val = (getline(&cmd, &n, stdin));
		if (val == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (cmd[i])
		{
			if (cmd[i] == '\n')
				cmd[i] = 0;
			i++;
		}
		j = 0;
		argv[j] = strtok(cmd, " \n");
		while (argv[j])
		{
			argv[++j] = strtok(NULL, " \n");
		}
		firstp = fork();
		if (firstp == -1)
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
		if (firstp == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		wait(&status);
	}
}
