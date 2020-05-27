

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define MAXMSJ 32
int  main (){

	FILE *ap ;
	int r;	
	char *message;
	
	mensaje =malloc(MAXMSJ);
	if (mensaje== NULL){
		perror("error en malloc");
		exit(-1);	
	}
	sprintf(mensaje,"hola mundo");
// open file 
	ap=fopen("texto.txt","w+");
	if(ap ==NULL){
		perror("No se pudo abrir el archivo porque: ");
		exit(-1);
	}
// escritura en file 
	
	fwrite("hola mundo ",sizeof(char),10,ap);

// close file 
	r=fclose(ap);
	if(r != 0){
		perror("No se pudo abrir el archivo porque: ");
		exit(-1);
	}
	free(mensaje);
}

