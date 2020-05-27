#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define  FILE_LENGHT 400



int main(int argc, char * const argv[]){



FILE *f1;
int i;
char letter = ' ';
   clock_t start = clock();


/* Apertura del fichero de destino, para escritura en binario*/
f1 = fopen ("hola.txt", "w+");
if ( f1 == NULL)
{
   perror("No se puede abrir fichero2.dat");
   return -1;
}

 for(i = 0; i < ((1024*1024)*100); i++){
    fwrite (&letter,sizeof( char ),1, f1); 	
 }
    


    fclose (f1);

	printf("Tiempo transcurrido Llamada SO: %f", ((double)clock() - start) / CLOCKS_PER_SEC);
 



}
