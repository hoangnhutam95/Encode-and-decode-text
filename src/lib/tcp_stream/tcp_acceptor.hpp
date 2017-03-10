#ifndef _IO_TCP_ACCEPTOR_HPP
#define _IO_TCP_ACCEPTOR_HPP

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef _NETINET_IN_H
#include <netinet/in.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _TCP_STREAM_HPP
#include "tcp_stream.hpp"
#endif

using namespace std;

class TCP_Acceptor{
  int m_lsd;
  string m_address;
  int m_port;
  bool m_listening;
private:
  TCP_Acceptor(){}
public:
  TCP_Acceptor(int port, const char* address = "");
  ~TCP_Acceptor();
  int start();
  TCP_Stream* accept();
};

#endif /* Endf _TCP_ACCEPTOR_HPP */
