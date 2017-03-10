#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "tcp_stream.hpp"
#include "tcp_connector.hpp"
#include "tcp_acceptor.hpp"
#include <iostream>
 
using namespace std;
 
int main(int argc, char** argv){
  char line[256];
  TCP_Connector connector;
  TCP_Stream* stream;
  long leng, len;
  FILE *conf;
  int port;
  char server_addr[100];

  conf = fopen("/andromeda/client/config.conf", "r");
  if( NULL == conf){
    printf("File config not found!\n");
    return 1;
  }
  fscanf(conf, "%d", &port);
  while('\n' != fgetc(conf));
  fscanf(conf, "%s", server_addr);
  fclose(conf);

  if (argc != 4) {
    printf("usage: %s <Encrypt/Decrypt> <sourceFile> <outputFile>\n", argv[0]);
    return 1;
  }
  if( strcmp("Encrypt", argv[1]) && strcmp("Decrypt", argv[1])){
    printf("usage: %s <Encrypt/Decrypt> <sourceFile> <outputFile>\n", argv[0]);
    return 1;
  }
  stream = connector.connect(server_addr, port);
  memset(line, 0, sizeof(line));
  if( !strcmp("Encrypt", argv[1])){
    strcpy(line, "Encrypt");
  } else {
    strcpy(line, "Decrypt");
  }
  cout << "Sending request: " << line << " to server!\n";
  stream->sendDataSegment( line, strlen(line));
  stream->receiveDataSegment(line,  &leng);
  cout << "Server reply: " << line << "\n";
  if( strcmp("Oke", line)){
    printf("Watting \"Oke\" from server => Quit\n");
    delete stream;
    return 1;
  }
  if( FAIL == stream->sendFile(argv[2])){
    printf("Can't read file: %s\n", argv[2]);
    delete stream;
    return 1;
  }
  if( FAIL == stream->receiveFile(argv[3])){
    printf("Can't create result file on: %s\n", argv[3]);
    delete stream;
    return 1;
  }

  delete stream;
  return 0;
}
