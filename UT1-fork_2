#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid_abuelo, pid_nieto;
  pid_t pid_padre;
  
  
  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre

  pid_abuelo= fork();

  if (pid_abuelo == -1 ) //Ha ocurrido un error 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (pid_abuelo == 0 )  //Nos encontramos en Proceso hijo 
  {       
    pid_padre=fork();
    
    if(pid_padre == -1)
    {
    	printf("ERROR !!! No se ha podido crear el proceso hijo...");
    	exit(-1); 
    }
    if(pid_padre == 0)
    {
    	printf("Soy el proceso nieto y mi id es: %d \n",getpid());
    	printf("Soy el proceso nieto y el id de mi padre es: %d \n",getppid());
    }
    else     
    {
      wait(NULL);
    	printf("Soy el proceso padre y mi id es: %d \n",getpid());
    	printf("Soy el proceso padre y el id de mi padre es: %d \n",getppid());
    }
    
  }
  else    
  {
   wait(NULL);
   printf("Soy el proceso abuelo y mi id es: %d \n",getpid());
   printf("Soy el proceso abuelo y el id de mi padre es: %d \n",getppid());          
  }
  
   exit(0);
}
