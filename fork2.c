#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p1;

  
  p1 = fork(); //se crea el primer hijo P2	

  if (p1 == -1 ) 
  {
    printf("No se ha podido crear el proceso padre"); //Control de errores
    exit(-1);       
  }
  if (p1 == 0 )   
  {        
    
    pid_t p2;
    
    p2=fork();
    
    if(p2==-1)
    {
    	printf("No se ha podido crear el proceso padre"); //Control de errores
    	exit(-1); 
    }
    if(p2== 0)
    {
    	    pid_t p3;
    	    
    	    p3=fork();
    	    
    	    if(p3 == -1)
    	    {
    	    	printf("No se ha podido crear el proceso padre"); //Control de errores
    		exit(-1);
    	    }
    	    if(p3 == 0)
    	    {
    	    	 printf("Soy el proceso P4, mi pid es: %d y el pid de mi padre es: %d \n",getpid(),getppid()); //Proceso P3
	    	 printf("La suma de las pids son: %d \n",getpid()+getppid()); //Proceso P3
    	    }
    	    else
    	    {
    	    	wait(NULL);
    	    	
    	    	printf("Soy el proceso P3, mi pid es: %d y el pid de mi padre es: %d \n",getpid(),getppid()); //Proceso P3
	    	printf("La suma de las pids son: %d \n",getpid()+getppid()); //Proceso P3
    	    }
    }
    else
    {
    	wait(NULL);
    	
    	printf("Soy el proceso P2, mi pid es:%d y el pid de mi padre es: %d \n",getpid(),getppid()); //Proceso P2
    	printf("La suma de las pids son: %d \n",getpid()+getppid()); //Proceso P2
    }  
  }
  else    
  { 
    wait(NULL); //Proceso P1
    
    printf("Soy el proceso P1, mi pid es: %d y el pid de mi padre es: %d \n",getpid(),getppid()); //Proceso P3
    printf("La suma de las pids son: %d \n",getpid()+getppid()); //Proceso P3
    
  }
  exit(0);
}
