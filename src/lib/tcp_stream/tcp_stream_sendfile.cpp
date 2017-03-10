#include "tcp_stream.hpp"

int TCP_Stream::sendFile(char* path){
  FILE *fp;
  long lSize, loadedsize;
  char message[100];
  char cache[30000];

  memset(message, 0, sizeof(message));  
  printf("Start send file: %s\n", path);
  fp = fopen(path, "rb");
  if(NULL == fp){
    strcpy(message, "Open file: Failed");
    this->sendDataSegment(message, strlen(message) + 1);
    return FAIL;
  } else {
    strcpy(message, "Open file: Success");
    this->sendDataSegment(message, strlen(message) + 1);
  }
  printf("%s\n", message);
  this->receiveDataSegment(message, &loadedsize);
  if( strcmp("Ready!", message) ){
    return FAIL;
  }

  // obtain file size:
  fseek (fp , 0 , SEEK_END);
  lSize = ftell (fp);
  rewind (fp);

  // Send lengfile;
  this->send( (char*)&lSize, sizeof(lSize));
  printf("Start send file!\n");
  loadedsize = fread( cache, 1, 1024, fp);
  while( (loadedsize > 0) && (lSize > 0)){
    this->send(cache, loadedsize);
    lSize -= loadedsize;
    if(lSize < 1){
      break;
    }
    loadedsize = fread( cache, 1, 1024, fp);
  }
  fclose(fp);
  return SUCCESS;
}
