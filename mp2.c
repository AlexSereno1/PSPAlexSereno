#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t abuelo, padre, nieto;

  abuelo= fork();

  if (abuelo == -1 )  
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);       
  }
  if (abuelo == 0 )  
  {       
    padre=fork();
    
    if(padre == -1)
    {
    	printf("No se ha odido crear el proceso hijo");
    	exit(-1); 
    }
    if(padre == 0)
    {
    	printf("Soy el proceso PS3 y mi id es: %d \n",getpid());
    	printf("Soy el proceso PS3 y el id de mi padre es: %d \n",getppid());
    }
    else     
    {
      	wait(NULL);
    	printf("Soy el proceso PS2 y mi id es: %d \n",getpid());
    	printf("Soy el proceso PS2 y el id de mi padre es: %d \n",getppid());
    }
    
  }
  else    
  {
   wait(NULL);
   printf("Soy el proceso PS1 y mi id es: %d \n",getpid());
   printf("Soy el proceso PS1 y el id de mi padre es: %d \n",getppid());          
  }
  
   exit(0);
}
