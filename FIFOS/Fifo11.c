
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>

int main(void)
{
	int fd,num,fd2,resul;
	time_t t;
	
	mkfifo("/tmp/FIFO" , 0666);
	mkfifo("/tmp/FIFO2" , 0666);
	
	fd = open("/tmp/FIFO", O_WRONLY);
	
	
    	
    	srand((unsigned) time(&t));
	num= rand() % 11; 
	write(fd,&num,sizeof(num));
	close(fd);
	
	sleep(1);
	
	fd2=open("/tmp/FIFO2",O_RDONLY);
	
	read(fd2,&resul,sizeof(resul));
	
	printf("El factorial es: %d \n",resul);
	close(fd2);
    		
	unlink("/tmp/FIFO");
	unlink("/tmp/FIFO2");
	
	return 0;

}
