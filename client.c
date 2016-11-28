#include "Reseau.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX 500
int main(int argc, char *argv[]){

//  int client;  
  int i;
  while(i){
  i = socketClient("localhost", 9000, TCP);
  char message[MAX];
  fgets(message, MAX, stdin);
  afficheInfosSocket(i);
  connect(i, NULL, 0);
  write(i, message,MAX);    
  i++;
  }
  return 0;
}
