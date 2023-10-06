#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p1, p2,p3;

  
  p1 = fork(); //se crea el primer hijo P2	

  if (p1 == 0 )   
  {        
    
    if(getpid() % 2 == 0)
    {
    	 printf("Soy el proceso P2, mi id es: %d y el id de mi padre es: %d \n",getpid(),getppid()); 
    }
    else
    {
    	 printf("Soy el proceso P2, mi id es: %d \n",getpid()); 
    }
   
  }
  else    
  { 
    wait(NULL); //Proceso P1
    
    p2 = fork(); //Se crea el roceso P3
    
   
    if(p2 == 0) //Codigo de P3
    {
   	
   	
    	
   	p3=fork();
   	
   	if(p3==0)
   	{
		if(getpid() % 2 == 0)
    		{
    	 		printf("Soy el proceso P4, mi id es: %d y el id de mi padre es: %d \n",getpid(),getppid()); 
    		}
    		else
    		{
    	 		printf("Soy el proceso P4, mi id es: %d \n",getppid()); 
    		}
   	}
   	else
   	{
   		wait(NULL);
   		
   		if(getpid() % 2 == 0)
    		{
    	 		printf("Soy el proceso P3, mi id es: %d y el id de mi padre es: %d \n",getpid(),getppid()); 
    		}
    		else
    		{
    	 		printf("Soy el proceso P3, mi id es: %d \n",getpid()); 
    	 	
    		}
   	}
    }
    else
    {
   	wait(NULL);
   	
   	if(getpid() % 2 == 0)
    	{
    	 	printf("Soy el proceso P1, mi id es: %d y el id de mi padre es: %d \n",getpid(),getppid()); 
    	}
    	else
    	{
	 	printf("Soy el proceso P1, mi id es: %d \n",getpid()); 
    	}
    }	      
  }
   exit(0);
}
