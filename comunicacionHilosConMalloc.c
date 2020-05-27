#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define CICLES 1000
#define MAXHILOS 4


/* 	
	Objetivo:
		Sumar los numeros desde 1 hasta 750 
		Se dividira en 3 Hilos cada hilo realizara 250 ciclos que sumaran (0-250,250-500,500-750)
		Se cerraran los ciclos y se sumaran los resultados conseguidos
	funcion sera la funcion que se le pasara al hilo para que ejecute
	se recibe un apuntador *ap2(para poder dirigirse a memoria)
*/

struct data{ /*Datos para la ejecucion de cada hilo*/
	int inicioIteraciones;
	int finIteraciones;
	double resultado ;
};

void * funcion(void * config ){

	struct data * pi2;
	pi2 = config;
	//int number = pi2->tarea;	//printf("A%i",number);
	printf("Init:%i|",pi2->inicioIteraciones);
	//printf("End:%i|",pi2->finIteraciones);
	for (int i = pi2->inicioIteraciones ; i < (pi2->inicioIteraciones*2) ; ){
	    pi2->resultado=pi2->resultado-(double)(4.0)/(double)(i+=2);
		pi2->resultado=pi2->resultado+(double)(4.0)/(double)(i+=2); // pow (-1.i) -> hace mas lento codigo
	}
}

void main(void){
	pthread_t hilos[MAXHILOS]; //Se crea un arreglo de hilos
	int * returnval;
	int i, r;
	

	struct data * blockData[MAXHILOS];	/*Comunicacion de los hilos*/
		
	for(i = 0; i < MAXHILOS; i++){
		blockData[i] = malloc(sizeof(struct data));
		blockData[i]->inicioIteraciones = 0 ;	
	}

	for(i = 0; i < MAXHILOS; i++){

		blockData[i]->inicioIteraciones = i * 250;
		//blockData[i]->finIteraciones	= i+1 * (CICLES/MAXHILOS);
		blockData[i]->resultado	= 0;
		r = pthread_create(&hilos[i], NULL, funcion, (void*) (void*)blockData[i]);
		if(r == 0){
			printf("Hilo %i creado", i);
		}else{
			perror("Error en hilo");
		}
	}

	for(i = 0; i < MAXHILOS; i++){
	/*Se cierra el hilo para poder cerrar el padre*/
		
		r = pthread_join(hilos[i], (void**) &returnval);
		if(r == 0){
			printf("Hilo %i cerrado", i);
		}else{
			perror("Error en hilo");
		}
	}
	
	for(int i = 0 ; i < MAXHILOS ; i++){
		printf("\n%f",blockData[i]->resultado) ;	
	}

}
