#include "tcp_connector.hpp"

int TCP_Connector::resolveHostName(const char* hostname, struct in_addr* addr){
  struct addrinfo *res;
  int result;

  result = getaddrinfo(hostname, NULL, NULL, &res);
  if(0 == result){
    memcpy(addr, &((struct sockaddr_in*)res->ai_addr)->sin_addr, sizeof(struct in_addr));
    freeaddrinfo(res);
  }
  
  return result;
}
