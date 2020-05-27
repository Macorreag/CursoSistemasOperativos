#include <sys/types.h>          
#include <sys/socket.h>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include <strings.h>
#include <netinet/in.h>

#define PORT 3535
#define BACKLOG 0

/*Configuración Socket MODO SERVIDOR*/


int main(){
    int serverfd,r,clientfd;
    struct sockaddr_in server,client;
    socklen_t size =sizeof(struct sockaddr_in);
    socklen_t size_cli;
    
    char buffer[32];
    
    
    serverfd=socket(AF_INET,SOCK_STREAM,0);/*creación server*/ 
    if(serverfd == -1){
        perror("Error Socket");
    }
    server.sin_family =AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=INADDR_ANY;
    bzero(server.sin_zero,8);//rellena de zeros
    r=bind(serverfd,(struct sockaddr *)&server,size);//bautizo socket
    if(r<0){
    perror("error bind"); }
    r=listen(serverfd,BACKLOG); //configguracion de escucha
    if(r<0){
    perror("error listen ");
    }
    clientfd=accept(serverfd,(struct sockaddr *)&client,(socklen_t*)& size_cli);//crear la creacion para recibir msj
    
    if(clientfd<0){perror("err");}
    r=recv(clientfd,buffer,32,0);
    if(r<=0){
        perror("error");
    }
    printf("%s",buffer);
    close(clientfd);
    close(serverfd);
    
    

}

