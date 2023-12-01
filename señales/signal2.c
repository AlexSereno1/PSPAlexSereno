#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


void suma()
{
	int segundos=0;
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
