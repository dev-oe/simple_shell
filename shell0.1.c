#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define PROMPT "cisfun$"

/**
 * main - starting piont
 *
 * Return: Always 0 on success
*/
int main(void)
{
	char cmd[MAX_CMD_LEN];
	char *argv[2] = {NULL, NULL};
	char *envp[] = {NULL};

	pid_t pid;

	while (1)
	{
		printf("\n");
		break;

	}

	cmd[strcspn(cmd, "\n")] = '\0';
	if (strlen(cmd) == 0)
		continue;

	argv[0] = cmd;

	pid = fork();
	if (pid == 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error")
	}
	else
	{
		wait(NULL);
	}

	return (0);


}
