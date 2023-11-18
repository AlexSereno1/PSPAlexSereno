#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{
    	int fd1[2],fd2[2];	
    	pid_t hijo;
    	int DNI;
    	char coso;

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
    		close(fd1[0]);
    		
	 	printf("Introduce el numero de tu DNI: ");
    		scanf("%d",&DNI);
    		
    		write(fd1[1], &DNI ,sizeof(DNI));
    		
    		close(fd2[1]);
    		read(fd2[0],&coso,sizeof(coso));
    		
    		printf("La letra es: %s\n",&coso);

    		
    	} 
    	else 
    	{ 
   
    		close(fd1[1]);
    		
		char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
		
		
		read(fd1[0], &DNI ,sizeof(DNI));
		//printf("DNI: %d \n",DNI);
		
		
		DNI %= 23; 
		coso=letra[DNI];
		
		close(fd2[0]);
		write(fd2[1],&coso,sizeof(coso));
    		
    		wait(NULL);
        	
	    	
	}	

}
