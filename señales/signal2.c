#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int segundos=0;

void suma()
{
	segundos = segundos+5;
	printf("Han trascurrido %d segundos \n",segundos);
	alarm(5);
}
int main() 
{ 
	signal(SIGALRM, suma);
	alarm(5);
	while(1)
	{
	
	}
} 
