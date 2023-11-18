#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{
    	int fd1[2],fd2[2];	
    	pid_t hijo;
    	int numero,resul = 1;

    	if (pipe(fd1) == -1) 
    	{
        
        perror("pipe");
        exit(EXIT_FAILURE);
    	}
    	
    	if (pipe(fd2) == -1) 
    	{
        
        perror("pipe");
        exit(EXIT_FAILURE);
    	}
    	
    	
	hijo = fork(); 
	
    	if (hijo == 0) 
    	{ 
    		int cont;
		close(fd1[1]);
		
		read(fd1[0], &numero ,sizeof(numero));
		
		
		if(numero != 0)
		{
			for(cont = 1  ; cont <= numero ;cont++)
			{
				resul = resul*cont;
			}
			
		}
		
		close(fd2[0]);
		
		write(fd2[1],&resul,sizeof(resul));
    	} 
    	else 
    	{ 
    		
    		close(fd1[0]);
    		time_t t;
    		
    		
    		srand((unsigned) time(&t));
		numero= rand() % 10; 
		
		printf("El proceso padre genera el numero %d en el pipe 1\n",numero);
		
		write(fd1[1], &numero ,sizeof(numero));
		
		wait(NULL);
		
    		close(fd2[1]);
    		
    		read(fd2[0],&resul,sizeof(resul));
    		
    		printf("El factorial calculado por el proceso hijo: %d ! = %d\n",numero,resul);
        	
	    	
	}	

}
