#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX 2000000000    

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

int main(){


    
	int child,sdId;
	size_t size=11;
	key_t key =1;
	char  *msj;
	msj=shmat(sdId,0,0);		
sdId=shmget(key,size,0666|IPC_CREAT); //pedir el espacio en memoria 

if (sdId==1){
	perror("error shmget:");
}
    printf("%s",msj);
		printf("%s","father");


}
