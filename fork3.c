#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p2,p3,p4,p5,p6;
  int p1_id,p2_id;
  
  p1_id =getpid();

  
  p2 = fork(); //se crea el primer hijo P2	

  if (p2 == -1 ) 
  {
    printf("No se ha podido crear el proceso padre"); //Control de errores
    exit(-1);       
  }
  if (p2 == 0 )   
  {       
  	//p2 
    p2_id=getpid();
    p4=fork();
    
    if(p4 == -1)
    {
    	printf("No se ha podido crear el proceso padre"); //Control de errores
    	exit(-1); 
    }
    if(p4 == 0)
    {
    	//p4
    	    p6=fork();
    	    
    	    if(p6 == -1)
    	    {
    	    	printf("No se ha podido crear el proceso padre"); //Control de errores
    		exit(-1);
    	    }
    	    if(p6 == 0)
    	    {
    	    	printf("Soy el proceso P6, mi pid es: %d y la pid de mi abuelo P2 es: %d \n",getpid(),p2_id);
    	    	
    	    }
    	    else
    	    {
    	    	wait(NULL); 	
    	    	printf("Soy el proceso P4, mi pid es: %d y el pid de mi abuelo P1 es: %d \n",getpid(),p1_id);
    	    }
    }
    else
    {
    	wait(NULL);
    	
    	p3=fork();
    	
    	if(p3 == -1)
    	{
		printf("No se ha podido crear el proceso padre"); //Control de errores
    		exit(-1);
    	}
    	if(p3 == 0)
    	{
    		//p3
    		p5=fork();
    		
    		if(p5 == -1)
    		{
    			printf("No se ha podido crear el proceso padre"); //Control de errores
    			exit(-1);
    		}
    		if(p5 == 0)
    		{
    			//p5
    			printf("Soy el proceso P5, mi pid es: %d y la pid de mi abuelo P2 es: %d \n",getpid(),p2_id);
    		}
    		else
    		{
    			wait(NULL);
    			printf("Soy el proceso P3, mi pid es: %d y la pid de mi abuelo P1 es: %d \n",getpid(),p1_id);
    		}
    	}
    	else
    	{
    		wait(NULL);
    		
    		
    		printf("Soy el proceso P2 y mi pid es: %d \n",getpid());
    		
    	}
    } 
  } 
  else    
  { 
  	wait(NULL); //Proceso P1 
  	printf("Soy el proceso P1 y mi pid es: %d \n",getpid());
  }
  exit(0);
}
