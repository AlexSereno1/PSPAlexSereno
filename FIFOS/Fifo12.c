//Proceso que lee del PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 



int main(void)
{
	int fd,num,resul=1,fd2;
	fd= open("/tmp/FIFO", O_RDONLY);
	
	read(fd,&num,sizeof(num));
	
	printf("Num: %d \n",num);
	close(fd);
	
	if(num != 0)
	{
		for(int i = 1  ; i <= num ;i++)
		{
			resul = resul*i;
		}
			
	}
	
	
	fd2 = open("/tmp/FIFO2",O_WRONLY);
	write(fd2,&resul,sizeof(resul));
	close(fd2);
	
	return 0;
}
