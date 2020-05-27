
	#include <stdlib.h>
	#include <stdio.h>
	#include <pthread.h>

	#define MAXHILOS 2

	struct foo
	{
		int ntareas;
		int tarea;
		int k;
		double resultado;
	};

	int i, r;

	void * serie_pi(void * pi)
	{
		struct foo * pi2;
		pi2 = pi;
		int number = pi2->tarea;
		printf("A%i",number);
/*		

		int tamtarea = pi2->k / pi2->ntareas;
		int fintarea = (pi2->tarea * tamtarea);
		int initarea = fintarea - tamtarea + 1;

		for(i = initarea; i < fintarea; i += 4)
		{
			pi2->resultado += (4.0/i) - (4.0 / (i + 2.0));
		}*/
	}

	int main(int argc, char * argv[])
	{
		int *retval;
		pthread_t hilos[MAXHILOS];
		struct foo * pi[MAXHILOS];	/*Comunicacion de los hilos*/
		
		for(i = 0; i < MAXHILOS; i++)
		{
			pi[i] = malloc(sizeof(struct foo));
		}

		for(i = 0; i < MAXHILOS; i++)
		{
			(*pi[i]).ntareas = MAXHILOS;
			pi[i]->tarea = i + 1;
			pi[i]->k = 1000000000;
		}

		for(i = 0; i < MAXHILOS; i++)
		{
			r = pthread_create(&hilos[i], NULL, serie_pi, (void*)pi[i]);
			if(r == 0){
				printf("Hilo creado \n");
			}else{
				perror("Error en el hilo");
		}
		}

		for(i = 0; i < MAXHILOS; i++)
		{	
			//printf("\nCerrado hilo no. %i", i + 1);
			r = pthread_join(hilos[i], (void**)&retval);
			if(r == 0){
				printf("Fin de hilo");
			}else{
				perror("Error en el fin de hilo");
			}
		}

		for(i = 0; i < MAXHILOS; i++)
		{
			pi[0]->tarea += pi[i + 1]->tarea;
		}

		printf("\n%i", pi[0]->tarea);
	}

