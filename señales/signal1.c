#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
void fin()
{
	time_t hora;
	char *fecha;
	time(&hora);
	fecha = ctime(&hora);
	printf("Fin del proceso %d : %s \n", getpid(),fecha);
}
int main() 
{ 
	signal(SIGINT, fin);
	
	time_t hora;
	char *fecha;
	time(&hora);
	fecha = ctime(&hora);
	
	printf("Inicio del proceso %d: %s \n",getpid(),fecha);
	sleep(100);
    	
} 
