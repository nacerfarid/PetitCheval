#include "Reseau.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <errno.h>

#define MAX 500
/*int main(int argc, char *argv[]){

//  int client;  
  int i;
  i = 1;
  while(1){
  i = socketClient("localhost", 9000, TCP);
  char message[MAX];
  fgets(message, MAX, stdin);
  afficheInfosSocket(i);
  connect(i, NULL, 0);
  write(i, message,MAX);    
  i++;
  }
  return 0;
}*/
int main(int argc, char *argv[]){
	int n;
	//int sockfd = socketClient("localhost", 9000, TCP);
   char buffer[256];
	while(1){
	int sockfd = socketClient("localhost", 9000, TCP);
	printf("chaine à envoyer: ");
	bzero(buffer,256);
	fgets(buffer,255,stdin);
	connect(sockfd, NULL, 0);
	n = write(sockfd,buffer,strlen(buffer));
	if (n < 0){
		perror("ERREUR ecriture socket");
	}
	bzero(buffer,256);
	n = read(sockfd,buffer,255);
	if (n < 0){
		perror("ERREUR lecture socket");
	}
	printf("%s\n",buffer);
	close(sockfd);
	
	}
	return 0;
}
