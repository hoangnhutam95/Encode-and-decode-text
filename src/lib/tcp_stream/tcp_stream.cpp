#include "tcp_stream.hpp"
TCP_Stream:: TCP_Stream(int sd, struct sockaddr_in* address) : m_sd(sd){
  char ip[50];
  inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr), ip, sizeof(ip) -1);
  m_peerIP = ip;
  m_peerPort = ntohs(address->sin_port);
  this->m_sd = sd;
}

ssize_t TCP_Stream::send(const char* buffer, size_t len){
  return write(m_sd, buffer, len);
}

ssize_t TCP_Stream::receive(char* buffer, size_t len) {
  return read(m_sd, buffer, len);
}

string TCP_Stream::getPeerIP(){
  return m_peerIP;
}

int TCP_Stream::getPeerPort(){
  return m_peerPort;
}
