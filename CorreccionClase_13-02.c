#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<math.h>
#include<stdlib.h>
#include<pthread.h>



int main(){
    
    FILE *ap; 			// Archivo a escribir 
	int pid = fork();   //creacion_Hijo
	int r;              //controlador error
    
	if(pid == -1){
    	perror("Error en fork");
        exit(0);
    }
    
    
    ap =fopen("texto.dat" , "w+");
    if (ap== NULL){   
        perror("No se puede crear o abrir el archivo porque:");
        exit(0);   
    }   
       


    if(pid== 0){    //proceso hijo 
        printf("Hijo");
        fwrite("Hijo", sizeof(char)*4,4, ap);   //escribir el archivo 
    }else{      //proceso padre 
        printf("Padre");
      	fwrite("Padre", sizeof(char)*5,4, ap);
	}
    
    	r = fclose(ap);		// Ordeno cerrar el archivo para no escribir mas 
    if ( r != 0){
        perror("No se puede cerrar el archivo");
    }
}

