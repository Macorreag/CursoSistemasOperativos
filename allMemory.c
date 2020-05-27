#include <stdio.h>
#include <stdlib.h>




int main (int argc,char * argv[]){

    char * data;
    
    
    
    
    float a = 0;
    
    float GB = 1024*(1024*1024);
    
    scanf("%f",&a);
    long int i = 0 ;
    data= (char *) malloc(GB*a);
    
    
    
        for( i = 0 ; i < (GB*a) ; i++ ){
            data[i]='a'; 
        }
    
    
    sleep(5);
    scanf("%f",&a);
    return 0;
}

