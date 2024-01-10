#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
	pid_t  P2, P3, P4, P5, P6;
	
	int abuelo1, abuelo2;
	
	abuelo1 = getpid();
	
	P2 = fork();
	
	if(P2 == 0)
	{
	
		abuelo2 = getpid();
	
		P3 = fork();
		
		if(P3 == 0)
		{
		
			P5 = fork();
			
			if(P5 == 0)
			{
			
				printf("PID del proceso P5: %d\n", getpid());
				printf("PID del proceso abuelo 2: %d\n", abuelo2);
			
			}else
			{
			
				wait(NULL);
				printf("PID del proceso P3: %d\n", getpid());
				printf("PID del proceso abuelo 1: %d\n", abuelo1);
			
			}
		
		}else
		{
		
			wait(NULL);
		
			P4 = fork();
			
			if(P4 == 0)
			{
			
				P6 = fork();
				
				if(P6 == 0)
				{
				
					printf("PID del proceso P6: %d\n", getpid());
					printf("PID del proceso abuelo 2: %d\n", abuelo2);
				
				}else
				{
				
					wait(NULL);
					printf("PID del proceso P4: %d\n", getpid());
					printf("PID del proceso abuelo 1: %d\n", abuelo1);
				
				}
			
			}else
			{
			
				wait(NULL);
				printf("PID del proceso P2: %d\n", getpid());
			
			}
			
		}
	
	}else
	{
	
		wait(NULL);
		printf("PID del proceso P1: %d\n", getpid());
		
	}
}
