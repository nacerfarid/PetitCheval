#include "Reseau.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <errno.h>

void lecture (int );
int main(int argc, char *argv[]){

  //int mes;
  int num;
  int newsockfd;
  pid_t pid;
  num = socketServer(9000,TCP);
  afficheInfosSocket(num);

	/*while(1){
  mes = accept(num, NULL, NULL);
  char message[100];
  int nb;
  nb = read(mes, message, 100);
  printf("%d\n",nb);
  printf("%s\n",message);
  }*/
	while (1) {
		newsockfd = accept(num, NULL, NULL);
		if (newsockfd < 0){ 
			perror("ERREUR accept");
		}
		pid = fork();
		if (pid < 0){
			perror("ERREUR du fork");
		}
		if (pid == 0)  {
			close(num);
			lecture(newsockfd);
			exit(0);
		}
		else{
			close(newsockfd);
		}
	}

	return 0;
}

void lecture (int sock)
{
   int n;
   char buffer[256];
      
   bzero(buffer,256);
   n = read(sock,buffer,255);
   if (n < 0) perror("ERREUR lecture socket");
   printf("Message: %s\n",buffer);
   n = write(sock,"Bien recu",9);
   if (n < 0) perror("ERREUR ecriture socket");
}
