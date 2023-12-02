#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int pipefd[2];

void handler(int signum) 
{
	if (signum == SIGUSR1) 
	{
		int num;
		read(pipefd[0], &num, sizeof(num));
		if (num == 0) 
		{
			printf("Proceso padre recibió 0. Finalizando...\n");
			close(pipefd[0]);
			exit(EXIT_SUCCESS);
		} 
		else if (num % 2 == 0) 
		{
			printf("Número par %d recibido por el proceso P2 con pid %d\n", num, getpid());
		} 
		else 
		{
			printf("Número impar %d recibido por el proceso P3 con pid %d\n", num, getpid());
		}
	}
}

int main() 
{
	pid_t pidP2, pidP3;

	if (pipe(pipefd) == -1) 
	{
		perror("Error en la creación del pipe");
		exit(EXIT_FAILURE);
	}

	signal(SIGUSR1, handler);

	pidP2 = fork();


	if (pidP2 == 0) 
	{ 
		lose(pipefd[1]); 
		pause(); 
		exit(EXIT_SUCCESS);
	} 
	else 
	{
		pidP3 = fork();

		if (pidP3 == 0) 
		{ 
		close(pipefd[1]); 
		pause(); 
		exit(EXIT_SUCCESS);
		} 
		else 
		{ 
			close(pipefd[0]); 
			while (1) 
			{
				int num;
				printf("Introduce número: ");
				scanf("%d", &num);
				write(pipefd[1], &num, sizeof(num)); 
				kill(pidP2, SIGUSR1); 
				kill(pidP3, SIGUSR1); 
				if (num == 0) 
				{
					wait(NULL); 
					wait(NULL);
					printf("Fin proceso padre con pid %d\n", getpid());
					exit(EXIT_SUCCESS);
				}

				sleep(1);
			}
		}
	}
}
