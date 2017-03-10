#include "tcp_acceptor.hpp"

TCP_Stream* TCP_Acceptor::accept(){
    struct sockaddr_in address;
    socklen_t len;
    int sd;
    
    if( m_listening == false){
      return NULL;
    }
    len = sizeof(address);
    memset(&address, 0, sizeof(address));
    sd = ::accept(m_lsd, (struct sockaddr*)&address, &len);
    while( sd <= 0){
      sd = ::accept(m_lsd, (struct sockaddr*)&address, &len);
    }
    /*if(sd < 0){
      perror("accept() failed!\n");
      return NULL;
      }*/

    
    return new TCP_Stream(sd, &address);
}
