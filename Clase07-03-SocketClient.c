#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>

#define PORT 3535

/*Socket  MODO CLIENTE */


int main(int argc,char * argv[]){ 
//argv[0]Nombre executable,[1]primer parametro VA EL PUERTO (BACKLOG),[2]segundo parametro separado por espacio 
    int clientfd,r; 
    
    clientfd=socket(AF_INET,SOCK_STREAM,0);
    /*  *AF_INET especifica coneccioón mediante ip_v4
        *SOCK_STREAM especifica tipo de tcp
    */
    
    struct sockaddr_in client;
    socklen_t size =sizeof(struct sockaddr_in );
    if(clientfd==0){
    perror("error socket");
    }
    client.sin_family=AF_INET;
    client.sin_port=htons(PORT); /*htons soluciona problema envianismo*/
    client.sin_addr.s_addr=inet_addr(argv[1]); //pasamos la direccion por parametro en el ./
    bzero(client.sin_zero,8);
    
    
    r=connect(clientfd,(struct sockaddr *)&client,size);
    if(r==-1){
        perror ("ERROR in conect");/*error al conectarse al servidor */
    }
    /**/
    r=send(clientfd,"hola mundo",10,0);
    if(r!=10){ //no se envio el paquete completo 
    ;
    }
    close(clientfd);




}
