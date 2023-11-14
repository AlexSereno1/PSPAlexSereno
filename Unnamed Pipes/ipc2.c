#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2]; 
    pid_t hijo;

    if (pipe(fd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }

    hijo = fork(); 

    if (hijo == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }

    if (hijo == 0) 
    { 
        close(fd[1]); 
        int sum = 0;
        int number;

        while (read(fd[0], &number, sizeof(int)) > 0) 
        {
            sum += number;
        }

        printf("El resultado es:  %d\n", sum);
    } 
    else 
    { 
        close(fd[0]); 

        int number;
        char input[10];

        while (1) 
        {
            printf("Introduce un numero ");
            scanf("%s", input);

            if (input[0] == '+') 
            {
                break;
            }

            number = atoi(input); 
            write(fd[1], &number, sizeof(int)); 
        }

        close(fd[1]);

    
        wait(NULL);
    }

}
