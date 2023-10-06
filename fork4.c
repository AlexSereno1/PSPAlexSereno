#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t p2,p3,p4,p5;

  int acumulado = getpid();
  
  p2 = fork(); //se crea el primer hijo P2	

  if (p2 == -1 ) 
  {
    printf("No se ha podido crear el proceso padre"); //Control de errores
    exit(-1);       
  }
  if (p2 == 0 )   
  {        
	p5=fork();
	
	
  	if(p5 == -1)
  	{
  		printf("No se ha podido crear el proceso padre"); //Control de errores
    		exit(-1);  
  	}
  	if(p5 == 0)
  	{
  		//p5
  		if(getpid() % 2 == 0)
  		{
  			printf("Soy el proceso P5 y si soy par la variable es: %d \n",acumulado+10);
  		}
  		else
  		{
  			printf("Soy el proceso P5 y si soy impar la variable es: %d \n",acumulado-100);
  		}
  	}
  	else
  	{
		wait(NULL);
		//p2
		
		if(getpid() % 2 == 0)
  		{
  			printf("Soy el proceso P2 y si soy par la variable es: %d \n",acumulado+10);
  		}
  		else
  		{
  			printf("Soy el proceso P2 y si soy impar la variable es: %d \n",acumulado-100);
  		}
		
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
  		p4=fork();
  		
  		if(p4 == -1)
  		{
  			printf("No se ha podido crear el proceso padre"); //Control de errores
    			exit(-1);  
  		}
  		if(p4 == 0)
  		{
  			if(getpid() % 2 == 0)
  			{
  				printf("Soy el proceso P4 y si soy par la variable es: %d \n",acumulado+10);
  			}
  			else
  			{
  				printf("Soy el proceso P4 y si soy impar la variable es: %d \n",acumulado-100);
  			}
  		}
	  	else
	  	{
	  		wait(NULL);
	  		
	  		if(getpid() % 2 == 0)
			{	
  				printf("Soy el proceso P3 y si soy par la variable es: %d \n",acumulado+10);
  			}
  			else
  			{
  				printf("Soy el proceso P3 y si soy impar la variable es: %d \n",acumulado-100);
  			}
	  	}
  	}
  	else
  	{
  		wait(NULL);
  		
  		if(getpid() % 2 == 0)
  		{
  			printf("Soy el proceso P1 y si soy par la variable es: %d \n",acumulado+10);
  		}
  		else
  		{
  			printf("Soy el proceso P1 y si soy impar la variable es: %d \n",acumulado-100);
  		}
  	}
  	
  }
  exit(0);
}
