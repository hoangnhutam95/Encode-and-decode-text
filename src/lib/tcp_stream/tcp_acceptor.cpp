#include "tcp_acceptor.hpp"

TCP_Acceptor::TCP_Acceptor(int port, const char* address) : m_lsd(0), m_port(port), m_address(address), m_listening(false){}

TCP_Acceptor::~TCP_Acceptor(){
  if(m_lsd > 0){
    close(m_lsd);
  }
}
