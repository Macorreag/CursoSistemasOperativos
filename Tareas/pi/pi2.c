
/*Programa calcula Pi la mitad el padre y la mitad el Hijo*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000000000          //cantidad de iteraciones para generar a pi

double calculoPi(int ini,int fin)
{
    double A = 0.0;
	for( ; ini < fin; ini+=2){
		A = A + (4.0/ini);
		ini+=2;
		A = A - (4.0/ini);
	}
	return A;

}
int main()
{

    FILE *ap;           //Apuntador de Archivo
    pid_t pid;          //Process ID retornado es el del padre
    int r=0;              //manejo errores
    double A,B;
    pid = fork();
    if(pid == -1)         //Error al generar el hijo
    {
        perror("no se pudo hacer el fork exitosamente");
        exit(-1);
    }
    if(pid != 0)            //padre pues es el ID que retorna
    {


        A=calculoPi(1,MAX/2);                       //Calcula  PI hasta max/2

        do
        {
            ap = fopen("numero.txt","r");        //apertura de archivo si no lo encuentra retorna NULL
        }
        while(ap == NULL);

        do
        {
            r = fread(&B,sizeof(double),1,ap);      //lee el primer dato de tipo double que se encuentra en el archivo
        }
        while(r !=1);                               //mantiene leyendo hasta que el r   cambie de valor
        A= A+B;                                     //Suma lo que calculo mas lo del hijo
        printf("%1.10f\n",A);                       //impresion de la suma de lo generado padre e HIjo

    }
    else                    //Hijo su ID es '0'
    {
        B=calculoPi(MAX+1,MAX);                           //Calcula PI desde MAX/2 hasta MAX

        ap = fopen("numero.txt","w+");              //crea el archivo
        if(ap == NULL)                              //si no pudo crear el directorio
        {
            perror("no se pudo crear el archivo");  //termina el programa
            exit(-1);
        }

        do
        {
            r = fwrite((void*)&B,sizeof(double),1,ap);   //Escribe la suma de los negativos de pi en el archivo
        }
        while(r !=1);                                      //lo intenta hasta escribir

        exit(0);                                        //fin
    }

}

