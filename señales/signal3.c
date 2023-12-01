#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
void man ()
{
	time_t t;
    	struct tm *info;
    	time(&t);
    	info = localtime(&t);

    	FILE *archivo;
    	archivo = fopen("salidas.txt", "a");
	fprintf(archivo, "Señal SIGINT recibida a las %02d : %02d : %02d \n", info -> tm_hour,info-> tm_min, info -> tm_sec);
	fclose(archivo);
    
}

int main() 
{
    signal(SIGINT, man);

    while(1)
    {
    }

   
}
