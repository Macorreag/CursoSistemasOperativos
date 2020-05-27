#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#include<stdlib.h>
#include<pthread.h>

#define ITER 100000000

int cal(double*pi,long int init ,int end){ //funcionCalculaMitadPI

	/*if(init == 1){
	    *pi=4.0;
	}else{
	    *pi=0.0;
	}	*/
	
	for (int i = init ; i < end ; ){
	    *pi=*pi-(double)(4.0)/(double)(i+=2);
		*pi=*pi+(double)(4.0)/(double)(i+=2); // pow (-1.i) -> hace mas lento codigo
	}
	return 0;	
}
int main(){
	FILE *ap = NULL;	//Creacion Pointer Archivo
	pid_t pid;
	int r; 		// retorno de FILE
	double a,b;	
	pid = fork(); 	//Creación Hijo 
	if(pid==-1){
		perror("No fue posible crear el proceso Hijo:");
	}
	if(pid==0){
		cal(&b,(ITER/2)+1,ITER); // Se calcula la mitad de Pi
		
		ap = fopen("data.dat","w+"); //Crea un archivo vacio para leer y escribir 

        if (ap == NULL){     //validacion apertura archivo
			perror("No se puede crear o abrir el archivo porque:");
            exit(-1);
		}   
		r = fwrite((void*)&b,sizeof(double),1,ap);//escribe en el archivo el calculo realizado

		r=fclose(ap);   //Cierra el archivo 
		exit(0);        //terminacion programa
	}else{
		cal(&a,1,(ITER/2));		//Se Calcula la mitad de Pi
		
		do{
			ap=fopen("data.dat","w+");
		}while( ap == NULL ); //valida hasta que el archivo exista

		        do{
			        r = fread(&b,sizeof(double),1,ap);
		        }while(r!=1); //hasta q logre leer todos los bytes del dato
		     
		        r=fclose(ap); //cierra archivo 
		        if ( r != 0){
                    perror("No se puede cerrar el archivo");
           		}
		
		        a=4+a+b;  // suma los 2 datos y resta
		        printf("%lf",a);
		
	}
	
}
