#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/*
	Para compilar es necesario indicar la libreria al compilador
		>gcc thisFile.c -o executable -pthread

	Mas informacion con
		> man pthread_create
	
*/
#define NUMTHREADS 8

/*Funcion que ejecutara el nuevo hilo*/
void * funcion(void * arg ){
    int i=0;
	/*Semilla para numero aleatorio*/
    srand(time(NULL)); 
	/*r es un numero "Aleatorio"*/
    int r = rand();
    for(i=0;i<10000000;i++){        
        unsigned  long nHash = 0;
        int i;
        for ( i= 999; i >= 0; --i){
            nHash = r % 1000000007;
            r = rand(); 
        }
        printf("hola mundo %i \n" ,r % 1000);    
        printf("hola mundo %c \n	" ,*(int*)arg);
    }
}


int main(){
	pthread_t hilo;
	int arg = 0;
	int i,r;
	for( i = 0 ; i < NUMTHREADS ; i++ ){
		/*Se crea un nuevo hilo*/		
		r=pthread_create(&hilo,NULL,funcion,(void *)&arg);
		
		if(r<0){
			perror("error_pthread_create");
		}
	}
	for( i = 0 ; i < NUMTHREADS ; i++ ){
		/*Suspende la ejecución del subproceso de llamada hasta que finalice el subproceso de destino*/
		r=pthread_join(hilo,NULL);
		if( r != 0 ){
			perror("error_pthread_join");
		}
	}
}
