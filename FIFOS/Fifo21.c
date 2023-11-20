
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>

int main(void)
{
	int fd,num,resul;
	time_t t;
	
	mkfifo("/tmp/FIFO" , 0666);
	
	
	fd = open("/tmp/FIFO", O_WRONLY);
	
    	srand((unsigned) time(&t));
	num= rand() % 11; 
	write(fd,&num,sizeof(num));
	
	close(fd);
	
	
	fd=open("/tmp/FIFO",O_RDONLY);
	
	read(fd,&resul,sizeof(resul));
	
	printf("El factorial es: %d \n",resul);
	close(fd);
    		
	unlink("/tmp/FIFO");
	
	return 0;

}
