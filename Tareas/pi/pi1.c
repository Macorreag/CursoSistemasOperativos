
/*Programa calcula Pi los positivos suma el  padre y negativos el Hijo*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 2000000000          //cantidad de iteraciones para generar a pi

double calculoPi(int ini,int flag)
{
    double pi=0;
    if (flag)
    {
        for( ; ini < MAX ; ini+=4)
        {
            pi= pi + (4.0/ini);
        }
    }
    else
    {
         for( ; ini < MAX ; ini+=4)
        {
            pi= pi - (4.0/ini);
        }

    }
    return pi;


}
int main()
{
    int child,sdId;
	size_t size=11;
	key_t key=1 ;
	char *msj;		
sdId=shmget(key,size,0666|IPC_CREAT); //pedir el espacio en memoria 
printf("%s",msj);
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


        A=calculoPi(1,1);                       //Calcula positivos de PI

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
        B=calculoPi(3,0);                           //Calcula PI mediante la funcion solo negativos

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
