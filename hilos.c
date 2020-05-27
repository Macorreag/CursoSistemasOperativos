#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>

#define MAXHILOS 1

/* funcion sera la funcion que se le pasara al hilo para que ejecute
	se recibe un apuntador *ap2(para poder dirigirse a memoria)
*/
void * funcion(void *ap2){
	int *ap;	//Se crea un apuntador con tipo de dato que entrara
	ap = ap2;	//Se pone a apuntar en la direccion de memoria deseada
	printf("Hola hijo: %i", *ap);//Se imprime el valor asignado por el padre
}

void main(void){
	pthread_t hilos[MAXHILOS]; //Se crea un arreglo de hilos
	int * returnval;
	int arg[MAXHILOS];
	int i, r;

	for(i = 0; i < MAXHILOS; i++){
		arg[i] = i;
	}

	for(i = 0; i < MAXHILOS; i++){
		r = pthread_create(&hilos[i], NULL, funcion, (void*) &arg[i]);

			if(r == 0)	{ printf("Hilo %i creado", i); }
			else		{ perror("Error en hilo"); }
		}

		for(i = 0; i < MAXHILOS; i++)
		{
			/*Se cierra el hilo para poder cerrar el padre*/
			r = pthread_join(hilos[i], (void**) &returnval);

			if(r == 0)	{ printf("Hilo %i cerrado", i); }
			else		{ perror("Error en hilo"); }
		}
}
