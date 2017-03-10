#include "tcp_acceptor.hpp"

int TCP_Acceptor::start(){
  struct sockaddr_in address;

  int optval, result;

  if(m_listening == true){
    return 0;
  }

  m_lsd = socket(PF_INET, SOCK_STREAM, 0);
  memset(&address, 0, sizeof(address));
  address.sin_family = PF_INET;
  address.sin_port = htons(m_port);
  
  if( m_address.size() > 0){
    inet_pton(PF_INET, m_address.c_str(), &(address.sin_addr));
  } else {
    address.sin_addr.s_addr = INADDR_ANY;
  }

  optval = 1;
  setsockopt(m_lsd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
  result = bind(m_lsd, (struct sockaddr*)&address, sizeof(address));
  if(result != 0){
    perror("bind() failed!\n");
    return result;
  }

  result = listen(m_lsd, 5);
  if( result != 0){
    perror("listen() failed!\n");
    return result;
  }

  m_listening = true;

  return result;

}
