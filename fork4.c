#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
	pid_t P2, P3, P4, P5;
	
	int acumulado;
	
	acumulado = getpid();
	
	P2 = fork();
	
	if(P2 == 0)
	{
	
		P5 = fork();
		
		if(P5 == 0)
		{
		
			if(getpid()%2 == 0)
			{
			
				printf("P5 de PID: %d\n", acumulado + 10);
			
			}else
			{
			
				printf("P5 de PID: %d\n", acumulado - 100);
			
			}
		
		}else
		{
		
			wait(NULL);
		
			if(getpid()%2 == 0)
			{
			
				printf("P2 de PID: %d\n", acumulado + 10);
			
			}else
			{
			
				printf("P2 de PID: %d\n", acumulado - 100);
			
			}
		}
	
	}else
	{
		
		P3 = fork();
		
		if(P3 == 0)
		{
		
			P4 = fork();
			
			if(P4 == 0)
			{
		
				if(getpid()%2 == 0)
				{
				
					printf("P4 de PID: %d\n", acumulado + 10);
				
				}else
				{
				
					printf("P4 de PID: %d\n", acumulado - 100);
				
				}
			
			}else
			{
				
				wait(NULL);
				
				if(getpid()%2 == 0)
				{
				
					printf("P3 de PID: %d\n", acumulado + 10);
				
				}else
				{
				
					printf("P3 de PID: %d\n", acumulado - 100);
				
				}
								
			}
		
		}else
		{
			wait(NULL);
			wait(NULL);
			
			if(getpid()%2 == 0)
			{
			
				printf("P1 de PID: %d\n", acumulado + 10);
			
			}else
			{
			
				printf("P1 de PID: %d\n", acumulado - 100);
			
			}
		
		}
	
	}
}
