/* lector_fifo.c - Tuberia con nombre usando mkfifo */
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/mode.h>

int linea ();

int main ()
    {
    int descr;
    char cadena[100];

    unlink ("tuberia");     /*Desligamos la tuberia nombrada */
    mkfifo ("tuberia", 0);  /*Creamos una tuberia sin permisos*/
    chmod ("tuberia", 460); /*Cambiamos los permisos en "Tuberia"*/
    descr = open ("tuberia", O_RDONLY); /*Abrimos la tuberia*/
    while (linea (descr, cadena))
         printf ("%s\n", cadena);
    close (descr);
    pritnf ("Fin del lector.\n");
    }

int linea (int df, char *cad)
    {
    int n;

    do
      {
      n = read (df, cad, 1);    /*Leemos de a 1 byte y guardamos en cad*/
      }
    while (n > 0 && *cad++ != NULL);
    return (n > 0);
    }
