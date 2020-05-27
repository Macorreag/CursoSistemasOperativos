#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>

/*Memoria Compartida emparentada
*/

int main(){

	int child,sdId;
	size_t size=11;
	key_t key=1 ;
	char *msj;		
sdId=shmget(key,size,0666|IPC_CREAT); //pedir el espacio en memoria 

if (sdId==1){
	perror("error shmget:");
}
msj=shmat(sdId,0,0);
/*if(msj==-1){
	perror("error shmmat:");
}
*/

child = fork();		/*Creacion subproceso*/
	if (child == -1){
	
		error("Could not fork, QUIT!");

	  }
	if(child == 0){ /*Child process */
		
		sprintf(msj,"Hola mundo");
		printf("%s","child");
		

				
   		   
  	}else { /* This is the parent Process */
    		sleep(2);
		printf("%s",msj);
		printf("%s","father");
		


	}
		//shmdt(msj);

}
