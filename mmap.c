#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#define  FILE_LENGHT 1024



int main(int argc, char * const argv[]){
    
    
    clock_t start = clock();
    int fd,i ;
    char letter='e';
    void * file_memory;
    
    fd = open( argv[1], O_RDWR | O_CREAT | O_APPEND,S_IRUSR |S_IWUSR);
    
    file_memory = mmap(0,FILE_LENGHT,PROT_WRITE,MAP_SHARED,fd,0);
    
    for(i = 0; i < ((1024*1024)*100); i++){
    	//*file_memory = "a";
    	unsigned long x=(unsigned lo(unsigned long )file_memory     ); /*Movemos a la posicion del perro */	
        unsigned long * place = (unsigned long  * ) x;
        *place = letter;
    	x=(x + 1);
    	//file_memory = file_memory + 1; 
     	//sprintf((char*) file_memory + (1) , "\n%03d" , letter );
    }
    
	
	
	munmap(file_memory ,FILE_LENGHT);
	
	
	close(fd);
	
	printf("Tiempo transcurrido en MMAP: %f", ((double)clock() - start) / CLOCKS_PER_SEC);
 
    
	return 0;
}
