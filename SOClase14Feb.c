#include <stdio.h>
#include <unistd.h>
#include<errno.h>
#include<math.h>
#include <stdlib.h>
#include <pthread.h>

//#define  MAXMS = 32


int main(){
    pid_t pid;
    pid = fork();
    if(pid == -1){
    perror("Error en fork");
    //exit(-1);
}
    FILE *ap;
    int r;
    /*char *mensaje;
   
    mensaje = malloc(MAXMS);
    if(mensaje==NULL){
        perror("error en malloc");
        exit(-1);
    }*/
    ap =fopen("texto.txt" , "w+");
    if (ap== NULL){
   
        perror("No se puede crear o abrir el archivo porque:");
        exit(-1);   
    }   
       
    //fwrite("Hola mund2o" , sizeof(char), 10, ap);
    size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);

    r = fclose(ap);
    if ( r != 0){
        perror("NO se puede cerrar el archivo");
   }  
int a;
int i;
int sum1= 1;
int sum2;
int *sumA=sum2;
    if(pid== 0){
     printf("Soy el hijo  ");
    for( i=1; i < 10000000; i++){

           //sum2=sum1/i;
        //fwrite(&sumA, sizeof(int), 100, ap);
         //fputc(sumA,ap);
    }

    }else{
        printf("soy tu padre");
        
        for(a=10000000; a < 20000000; a++){
;
    }
    }
//exit(-1);
}
