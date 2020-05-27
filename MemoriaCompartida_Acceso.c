/*
 * shm-client - lee un espacio de memoria compartido conocido por el KEY
 * 5678 y lee lo que esta alli hasta encontrar el caracter '\0'
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ     27

main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     *Nombre del segmento que estamos usando
      */
    key = 5678;

    /*
     * Solicitamos al SO que nos de el ID  del espacio en memoria 
     *con KEY =5678 y del mismo tamaño.
     */
    if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    /*
     * Hacemos el attach del espacio de memoria y validamos que sea 
     *correcto .
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    /*
     * Leemos el espacio en memoria  
     */
    for (s = shm; *s != '\0'; s++)
        putchar(*s);
    putchar('\n');

    /*
     * Levantamos la bandera para indicar que la lectura finalizo 
     */
    *shm = '*';

    exit(0);
}

