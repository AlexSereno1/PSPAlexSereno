#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t padre, hijo;

  
  padre = fork();

  if (padre == -1 ) 
  {
    printf("No se ha podido crear el proceso padre");
    exit(-1);       
  }
  if (padre == 0 )   
  {        
    printf("Soy el proceso hijo ... \n");
    char nombre [4] = "Alex";
    printf("Mi nombre es: %s \n, y mi id es: %d ",nombre,getpid());	  
    
  }
  else    
  { 
   hijo = wait(NULL); 
   
   printf("Soy el proceso padre\n");
   printf("El id del proceso padre es: %d , el id del roceso hijo es: %d \n ",getpid(),padre);          
  }
   exit(0);
}
