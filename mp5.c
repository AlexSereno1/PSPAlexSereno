#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
  pid_t pid1, pid2;
  
  printf("AAA \n");
  
  pid1 = fork(); //Crear proceso hijo P2
  
  if (pid1==0)
  {
     printf("BBB \n"); //Proceso hijo P2

  }
  else
  {
     wait(NULL);
     pid2 = fork(); //Crear proceso hijo P3
     if(pid2 == 0)
     {
        printf("CCC \n");  
     }
     else
     {
     	wait(NULL);
     }
  }
  exit(0);
}

/* 
	a)Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendo
que el pid del programa mp5 es el 1000 y los pids se generan de uno en uno en orden creciente.
	El id del proceso padre serian 1000, los id de P2 y P3 dependen de cuando los ejecute el procesador.Si ejecuta primero el P2 la id de este seria 1001 y la id del P3 seria de 1002.
	
b)¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
	La ejecucion es AAA
		        CCC
		  promt+BBB
		  	CCC
Si se podria producir otra salida ya que, al no haber wait, se puede acabar la ejecucion del proceso padre antes que la ejecucion de los hijos
*/

	
