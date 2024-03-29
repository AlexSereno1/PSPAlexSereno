#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main() {
  pid_t pid, pid_hijo;
  pid_t PEPE;
  // Se crea un proceso hijo, la función fork() devuelve:
  // un valor negativo -> si se produce cualquier error
  // 0 -> si estamos en el proceso hijo
  // un valor positivo (pid del hijo) -> si estamos en el proceso padre
  PEPE = fork();
  if (PEPE == -1 ) //Ha ocurrido un error
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }
  if (PEPE == 0 )  //Nos encontramos en Proceso hijo
  {
    printf("Soy el proceso HIJO ... pid = %d ppid= %d \n",getpid(),getppid());	 
    printf("Soy el proceso HIJO ... Variable PEPE = %d \n",PEPE);	 
    printf("Voy a dormir 30 segundos ... \n");	 
    sleep(30);
  }
  else    //Nos encontramos en Proceso padre
  {
   pid_hijo = wait(NULL); //espera la finalización del proceso hijo
   printf("Soy el proceso PADRE ... pid = %d ppid= %d \n",getpid(),getppid());	
   printf("Soy el proceso PADRE ... Variable PEPE = %d \n",PEPE);	 
  }
   exit(0);
}

