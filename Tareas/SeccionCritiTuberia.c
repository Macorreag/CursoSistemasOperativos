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
    int t[2]; /*Controlador de  la tuberia */
    pipe( t );    	
    close( t[0] ); /* cerramos el lado de lectura del pipe */
    
    write( t[1] ,'T', sizeof(char) );/*Escribimos en el lado de escritura*/
    close( t[1] );  /*cerramos lado escritura*/
   
   
	
    //sem_wait(semaforo);/*Inicio seccion Critica*/
    char letter;
    //close( p[1] );  /*cerramos lado escritura*/    
   
	read(t[0],letter,sizeof(char));/*Leemos */
	    
    //close( p[0] );//cerramos lado lectura
	a = datos_proceso -> dato;
	p = datos_proceso -> p;
	for(i=0; i <= p; i++)
	{printf("%i ",a);}

	fflush(stdout);
	sleep(1);
	for(i=0; i<=p; i++)
	{
		printf("- ");
	}
	fflush(stdout);
	
	//close( p[0] ); /* cerramos el lado de lectura del pipe */
    
    write( t[1] ,letter, sizeof(char) );/*Escribimos en el lado de escritura*/
    //close( p[1] );  /*cerramos lado escritura*/
    
    
    //sem_post(semaforo);/*fin seccion critica  */
}


main()
{
	int error;
	//pipe( p ); 
	char *valor_devuelto,testigo;
	/* Variables para hilos*/
	struct datos_tipo hilo1_datos, hilo2_datos;
	pthread_t idhilo1, idhilo2, idhilo3, idhilo4;
	
	 

	hilo1_datos.dato = 1;
	hilo2_datos.dato = 2;
	hilo1_datos.p = 10;
	hilo2_datos.p = 5;
    
	/*semaforo= sem_open("semaforo_name", O_CREAT, 0700, MAX_PROCESOS);*/
    //close( p[0] ); /* cerramos el lado de lectura del pipe */
    
  //  write( p[1] ,'T', sizeof(char) );/*Escribimos en el lado de escritura*/
  //  close( p[1] );  /*cerramos lado escritura*/
   
   
	error=pthread_create(&idhilo1, NULL, (void *)proceso, (void *)      (&hilo1_datos));
	
	/*MANEJO DE HILOS
	*El primer parametro contiene donde se guardara el identificador del hilo
	*Segundo parametro especifica atributos del HILO si se deja en NULL el hilo inicia con los parametros normales
	*En este parametro le indicamos la funcion que debe ejecutar el hilo
	*En el cuarto parametro va las variables que deseamos enviar en especifico al hilo 
	*/
	
	
	
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

	
	
	pthread_join(idhilo2, (void **)&valor_devuelto);/*
	*Espera terminacion del hilo2 
	*En la primera variable va el ientificador del hilo a esperar
	*En el segundo parametro se da la variable donde se guardara el valor de retorno de la funcion ejecutada  */
	pthread_join(idhilo1, (void **)&valor_devuelto);/*Espera terminacion del hilo1 */

	//sem_close(semaforo);
	//sem_unlink("semaforo_name");

}
