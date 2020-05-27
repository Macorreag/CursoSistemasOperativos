/** 	compilar con math.h   -lm
** 	compilar con threads: -lpthread

    recuerde la sentencia de compilacion es 
    gcc Name.c -o NameExe -lpthread 
*/

#include <stdio.h>
#include <termios.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_PROCESOS 2
sem_t *semaforo;


struct datos_tipo{
    int dato;
	int p;
}
* proceso(void *datos){
	struct datos_tipo *datos_proceso;
	datos_proceso = (struct datos_tipo *) datos;
	int a, i, j, p;
    sem_wait(semaforo);
	a = datos_proceso -> dato;
	p = datos_proceso -> p;
	for(i=0; i <= p; i++){
	
	    printf("%i ",a);
	
	}

	fflush(stdout);
	
	sleep(1);
	
	for(i=0; i<=p; i++){
	
		printf("- ");
		
	}
	
	fflush(stdout);
	
    sem_post(semaforo);
}
main()
{
	int error;
	char *valor_devuelto;
	
	/* Variables para hilos*/
	
	struct datos_tipo hilo1_datos, hilo2_datos;
	
	pthread_t idhilo1, idhilo2, idhilo3, idhilo4;

	hilo1_datos.dato = 1;
	hilo2_datos.dato = 2;
	hilo1_datos.p = 10;
	hilo2_datos.p = 5;

	semaforo= sem_open("semaforo_name", O_CREAT, 0700, MAX_PROCESOS);

	error=pthread_create(&idhilo1, NULL, (void *)proceso, (void *)(&hilo1_datos));
	if (error != 0)
	{
		perror ("No puedo crear hilo");
		exit (-1);
	}

	error=pthread_create(&idhilo2, NULL, (void *)proceso, (void *)(&hilo2_datos));
	if (error != 0)
	{
		perror ("No puedo crear thread");
		exit (-1);
	}
	pthread_join(idhilo2, (void **)&valor_devuelto);
	pthread_join(idhilo1, (void **)&valor_devuelto);

	sem_close(semaforo);
	sem_unlink("semaforo_name");

}
