#include "tcp_connector.hpp"

TCP_Stream* TCP_Connector::connect(const char* server, int port){
  struct sockaddr_in address;
  int sd;

  memset( &address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(port);

  if(resolveHostName(server, &(address.sin_addr)) != 0){
    inet_pton(PF_INET, server, &(address.sin_addr));
  }

  sd = socket(AF_INET, SOCK_STREAM, 0);
  while ( ::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
    sleep(2);
  }

  return new TCP_Stream(sd, &address);
}
