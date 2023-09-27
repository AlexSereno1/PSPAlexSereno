#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p1, p2;

  
  p1 = fork(); //se crea el primer hijo P2	

  if (p1 == -1 ) 
  {
    printf("No se ha podido crear el proceso padre"); //Control de errores
    exit(-1);       
  }
  if (p1 == 0 )   
  {        
    printf("Soy el proceso P2 y me voy a dormir 10 segundos \n"); //Proceso P2
    sleep(10);	
    printf("Ya estoy despierto \n ");	  
  }
  else    
  { 
    wait(NULL); //Proceso P1
    
    p2 = fork(); //Se crea el roceso P3
    
    if(p2 == -1)
    {
   	printf("No se ha podido crear el proceso padre \n");//Control de errores
    	exit(-1);   	
    }
    if(p2 == 0) //Codigo de P3
    {
   	printf("El id del proceso P3 es: %d, y el de su padre es: %d \n",getpid(),getppid());
    }
    else
    {
   	wait(NULL);
    }	      
  }
   exit(0);
}
