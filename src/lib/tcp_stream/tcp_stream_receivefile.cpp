#include "tcp_stream.hpp"

int TCP_Stream::receiveFile(char* path){
  char message[100];
  char cache[30000];
  long leng_message, recsize;
  FILE *fp;
  
  printf("Start receive file: %s\n", path);
  this->receiveDataSegment(message, &leng_message);
  if( leng_message != (strlen("Open file: Success") + 1)){
    printf("Error when receive open file status!\n");
    return FAIL;
  }

  if( strcmp(message, "Open file: Success") != 0){
    printf("Open file: FAILED!\n");
    return FAIL;
  }
  fp = fopen(path, "wb");
  if(fp == NULL){
    printf("Can't create file!\n");
    sprintf(message, "Can't create file");
    this->sendDataSegment(message, sizeof(message) + 1);
    return FAIL;
  }
  sprintf(message, "Ready!");
  this->sendDataSegment(message, sizeof(message) + 1);

  printf("Start receive file!\n");
  // Get lengfile;
  this->receive( (char*)&leng_message, sizeof(leng_message));
  recsize = this->receive(cache, 1024);
  while( (recsize > 0) && (leng_message > 0)){
    fwrite(cache, 1, recsize, fp);
    leng_message -= recsize;
    if(leng_message < 1){
      break;
    }
    recsize = this->receive(cache, 1024);
  }

  fclose(fp);
  return SUCCESS;
}
