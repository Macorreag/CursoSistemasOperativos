#include<stdio.h>
#include<unistd.h>
#include<errno.h>

#include<stdlib.h>
#include<pthread.h>

#define ITER 1e09

int cal(double*pi,long int init ,int end){
		int i;
		*pi=0.0;
	if(i==1){
		*pi=4;			
		}
	for (i=init;i<end;){
	*pi=*pi-(double)(4.0)/(double)(i+=2);
	
	*pi=*pi+(double)(4.0)/(double)(i+=2); // pow (-1.i) -> hace mas lento codigo
		
			}
	
	return 0;	
}
int main(){
	FILE *ap;
	pid_t pid;
	int r; // retorno de FILE
	double a,b;	
	pid=fork();
	if(pid==-1){
		
		
	}
	if(pid==0){
		cal(&b,(ITER/2)+1,ITER);
		ap=fopen("data.dat","w+");
		
		
    if (ap == NULL){     //validacion apertura archivo 
        perror("No se puede crear o abrir el archivo porque:");
        exit(-1);   
    			}   
		r=fwrite((void*)&b,sizeof(double),1,ap);
		//printf("%07d",b);
		//validar escritura 
		r=fclose(ap);
		exit(0);
		}else{
				cal(&a,1,(ITER/2));
		
		do{
		ap=fopen("data.dat","w+");
		
		}while(ap==NULL);
		do{
			r=fread(&b,sizeof(double),1,ap);
			
		}while(r!=1);
		//printf("%07d",*b);
		r=fclose(ap);
		   if ( r != 0){
        perror("No se puede cerrar el archivo");
   				}
		
		a=a+b;
		printf("%lf",a);
		
			}
	
		}
