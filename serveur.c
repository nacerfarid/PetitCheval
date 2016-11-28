#include "Reseau.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){

  int mes;
  int num;
  pid_t child_serv;
  int tube_in[2];
  int tube_out[2];
  int tube[argv[3]][2];
  pipe(tube_in);
  pipe(tube_out);
  num = socketServer(9000,TCP);
  afficheInfosSocket(num);

  for(((child_serv = fork()) == 0){
  dup2(tube[0], STDIN_FILENO);
  close(tube[0]);
  mes = accept(num, NULL, NULL);
  char message[100];
  int nb;
  nb = read(mes, message, 100);
  printf("%d\n",nb);
  printf("%s\n",message);
  }
return 0;
}
