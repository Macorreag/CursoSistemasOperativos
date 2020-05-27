
 
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
//#include <sys/mode.h>

int main ()
    {
    int descr, longmens, i;
    char * mensaje;
    mensaje="HolaMundo";
    //printf ("Un saludo desde el proceso %d", getpid ());
    longmens = strlen (mensaje) + 1;
    do
      {		/* intentar la conexion */
      descr = open ("tuberia", O_WRONLY);
      if (descr == -1) sleep (1);
      }
    while (descr == -1);
    for (i=0; i<3; i++)
        {
        write (descr, mensaje, longmens);
        sleep (3);
        }
    close (descr);
    //printf("Fin del escritor %d\n", getpid ());
    }
    
