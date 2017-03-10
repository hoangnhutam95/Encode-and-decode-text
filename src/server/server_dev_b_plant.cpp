/*
  This program test tcp channel.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "tcp_stream.hpp"
#include "tcp_connector.hpp"
#include "tcp_acceptor.hpp"
#include <ctime>
 
int main(int argc, char** argv){
  TCP_Acceptor *acceptor;
  TCP_Stream *stream;
  char buffer[512] = {0};
  long leng, len;
  FILE* fp;
  char line[1024];
  pid_t pid;
  char isEncrypt;
  struct tm time;
  time_t t;

  FILE *conf;
  int port;

  conf = fopen("/andromeda/server/config.conf", "r");
  if( NULL == conf){
    printf("File config not found!\n");
    return 1;
  }
  fscanf(conf, "%d", &port);
  fclose(conf);

  isEncrypt = 0;

  acceptor = new TCP_Acceptor(port);
  acceptor->start();
  while(1){
    stream = acceptor->accept();
    pid = fork();
    if (pid ==  0){
      // child process
      cout << "Receiving request from client:\n";
      stream->receiveDataSegment(buffer, &leng);
      cout << "Received message: " << buffer << " from client!\n";
      if( strcmp("Encrypt", buffer) && strcmp("Decrypt", buffer) ){
	printf("Unknow request!\n");
	sprintf( buffer, "%s", "UnknowRequest");
	printf("Send: UnknownRequest to client\n");
	stream->sendDataSegment(buffer, leng);
	delete stream;
	return 0;
      }
      if( !strcmp("Encrypt", buffer)){
	isEncrypt = 1;
      }
      sprintf( buffer, "%s", "Oke");
      printf("Reply: Oke to client\n");
      stream->sendDataSegment(buffer, leng);      

      // Getfile
      sprintf(buffer, "/andromeda/server/");
      std::time(&t);
      time = *localtime(&t);
      sprintf( &(buffer[strlen(buffer)]),"F_%d_%d_%d_%d_%d_%d", time.tm_year + 1900, time.tm_mon + 1, time.tm_mday, time.tm_hour, time.tm_min, time.tm_sec);
      stream->receiveFile(buffer);
      if(isEncrypt){
	// Encrypt
	sprintf(line, "zpipe %s %s.encrypted", buffer, buffer);
	system(line);
	// Result file
	sprintf( &(buffer[strlen(buffer)]),".encrypted");
	stream->sendFile(buffer);
	// Delete file
	buffer[strlen(buffer) - 10] = 0;
	sprintf(line, "rm %s %s.encrypted", buffer, buffer);
	system(line);
      } else {
	// Decrypt
	sprintf(line, "zpipe %s %s.decrypted -d", buffer, buffer);
	system(line);
	// Result file
	sprintf( &(buffer[strlen(buffer)]),".decrypted");
	stream->sendFile(buffer);
	// Delete file
	buffer[strlen(buffer) - 10] = 0;
	sprintf(line, "rm %s %s.decrypted", buffer, buffer);
	system(line);
      }

      
      printf("All done!\n");
      delete stream;
      return 0;
    } else {
      if (pid > 0){
	// parent process
      } else {
        // fork failed
        printf("fork() failed!\n");
        return 1;
      }
    }
  }

  return 0;
}
