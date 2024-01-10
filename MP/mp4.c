#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>//añadimos include para poder usar wait
#include <sys/wait.h>//añadimos include para poder usar wait

void main()
{
 printf("CCC \n");  
 
 if (fork()!=0)
 {
    wait(NULL);
    printf("AAA \n");
    // codigo padre ya que solo se ejecuta este if si el fork es diferente de 0
    
 } else printf("BBB \n"); // codigo hijo ya que para ejecutarse, el fork tiene que dar 0
 
 exit(0);
}

/* a) Dibuja un gráfico de la jerarquía de procesos que genera la ejecución de este código, suponiendoque el pid del programa mp4 es el 1000 y los pids se generan de uno en uno en orden creciente.
	El id del padre seria 1000 y el del hijo 1001.
b)¿Qué salida genera este código? ¿Podría producirse otra salida? Justifica la respuesta
	La salida de este codigo será CCC
				       AAA
				 promt+BBB
	Esta salida puede variar en funcion de que roceso ejecute primero el procesador ya que 		le falta el wait. El promt sale debido a que el adre acaba antes que el hijo, dejando 		un proceso huérfano
*/
