#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int tiempo,repeticiones,contador=0;
void man()
{
	time_t t;
    	struct tm *info;
    	time(&t);
    	info = localtime(&t);
	
	printf("Señal alarma recibida a las -->  %02d : %02d : %02d \n", info -> tm_hour,info-> tm_min, info -> tm_sec);
	contador++;
	
	if(contador >= repeticiones)
	{
		printf("Alarma desactivada \n");
		exit(0);
	}
	else
	{
		alarm(tiempo);
	}
}
int main() 
{ 
	printf("¿Cuantas veces sonará la alarma?: \n");
	scanf("%d",&repeticiones);
	
	printf("¿Cada cuántos segundos se repetirá la alarma?: \n");
	scanf("%d",&tiempo);
	
	signal(SIGALRM,man);
	
	alarm(tiempo);
	
	while(1)
	{
	
	}
    	
} 
