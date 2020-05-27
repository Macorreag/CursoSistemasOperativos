
/*Programa para compartir memoria (escribe  el abecedario en ese espacio)*/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMSZ     27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * Nuestro segmento de Memoria compartida sera 
     * "5678".
     */
    key = 5678;

    /*
     * Creacion del segmento -1 signfica error 
     */
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);        //fin ejecucion 
    }

    /*
     * Ahora guardamos el id de nuestro attach de memoryshared
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     *guardaremos algo el la memory shared para que el otro 
     * proceso lea
     */
    s = shm;    /*Lo copiamos para no perder el original */

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = '\0';

    /*
     *Nuestra bandera sera el cambio de los caracteres por * 
     *por tanto esperamos a que el otro proceso logre 
     *odificar este 
     */
    while (*shm != '*')
        sleep(1);

    exit(0);
}
