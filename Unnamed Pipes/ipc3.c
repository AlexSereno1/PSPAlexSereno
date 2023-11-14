#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{
    	int fd[2]; 
    	pid_t hijo;
    	int numero1,numero2;

    	if (pipe(fd) == -1) {
        
        perror("pipe");
        exit(EXIT_FAILURE);
    }
	hijo = fork(); 
    	if (hijo == 0) 
    	{ 
    		close(fd[0]);
    		
		
 		
		srand(time(NULL));
		//Generamos numero aleatorio entre 1 y 50
		numero1= 1 + rand() % 50; 
		numero2= 1+ rand() % 50;
		
		write(fd[1], &numero1, sizeof(numero1)); 
		write(fd[1], &numero2, sizeof(numero2)); 
		
    	} 
    	else 
    	{ 
    		wait(NULL);
        	close(fd[1]); 
        	
	    	read(fd[0], &numero1, sizeof(numero1));
	    	read(fd[0], &numero2, sizeof(numero2));
	    	
	    	
	    	printf("%d + %d = %d \n",numero1,numero2,(numero1 + numero2));
	    	printf("%d - %d = %d \n",numero1,numero2,(numero1 - numero2));
	    	printf("%d * %d = %d \n",numero1,numero2,(numero1 * numero2));
	    	printf("%d / %d = %.2f \n",numero1,numero2,(float)(numero1/numero2));
	    	
	}	

}
