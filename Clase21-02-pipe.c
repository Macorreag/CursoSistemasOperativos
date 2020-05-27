#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Comucacion de procesos EMPARENTADOS  mediante tuberias PIPE
  *En este caso calculamos PI
 */ 

#define ITER 1e09
#define SIZE 40

int calc(double*pi,long int init ,int end){ //funcionCalculaMitadPI
	if(init == 1){
	    *pi=4.0;
	}else{
	    *pi=0.0;
	}
	int i;
	for( i = init ; i < end ; ){
	    *pi=*pi-(double)(4.0)/(double)(i+=2);
		*pi=*pi+(double)(4.0)/(double)(i+=2); // pow (-1.i) -> hace mas lento codigo
	}
	return 0;	
}



 
int main( int argc, char **argv )
{
    pid_t pid;
    int p[2], readbytes;
    double *pi;
    double num ;
    pipe( p );
    pi=&num;
    pid=fork(); /*Creacion Subproceso hijo */
    
  if ( (pid) == 0 )
  { /* hijo*/
    close( p[0] ); /* cerramos el lado de lectura del pipe */
    calc(pi,1,(ITER/2));
    write( p[1] , pi, sizeof(pi) );/*Escribimos en el lado de escritura*/
    close( p[1] );  /*cerramos lado escritura*/
   
  }
  else
  { /* padre*/
    double  a;
    close( p[1] );  /*cerramos lado escritura*/
    calc(&a,(ITER/2)+1,ITER);
    read(p[0],pi,sizeof(pi));/*Leemos */
    printf("%.*f",10 ,*pi+a);  /*Mostramos el calculado y el leido */
    close( p[0] );//cerramos lado lectura
  }
  
  
  exit( 0 );
}






