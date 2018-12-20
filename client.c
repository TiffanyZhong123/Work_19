#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  //1.Handshake
  from_server = client_handshake( &to_server );

  //2.Prompt user for input
  char input [BUFFER_SIZE];
  char servermsg [BUFFER_SIZE];
  while(1){
  printf("Enter message:");
  fgets(input,BUFFER_SIZE,stdin);

  //3.Send input to server
  printf("Writing input to server...\n");
  write(to_server,input,BUFFER_SIZE);

  //4.get response from server and display it to user
  printf("Reading response from server...\n");
  read(from_server,servermsg,BUFFER_SIZE);
  printf("Response from server: %s\n",servermsg);
}
  //5.Repeat steps 2-4 until interrupted
}
