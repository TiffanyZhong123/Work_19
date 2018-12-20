#include "pipe_networking.h"
#include <signal.h>
#include <string.h>
#include <stdio.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    remove("wkp");
    exit(0);
  }
}

void processdata(char *str){
  char *str1 = "!!!!!!!!";
  str = strncat(str,str1,BUFFER_SIZE + 10);

}

int main() {
  signal(SIGINT,sighandler);
  int to_client;
  int from_client;
  while(1){
  //1.Handshake
  from_client = server_handshake( &to_client );
  //2.Get data from client
  char clientdata[BUFFER_SIZE];
  while(read(from_client,clientdata,BUFFER_SIZE)){
  clientdata[strlen(clientdata) - 1 ] = '\0';
  printf("Getting data from client...\n");
  printf("Data from client: %s\n",clientdata);
  //3.Process data-do something interesting to it
  processdata(clientdata);
  //4.send processed data back to client
  write(to_client,clientdata,BUFFER_SIZE);
  printf("Sent message to client\n");
  //5.repeat until client exits
  //6.reset for a new Handshake
  //include signal handler for SIGINT that will be removed WKP
}
}


}
