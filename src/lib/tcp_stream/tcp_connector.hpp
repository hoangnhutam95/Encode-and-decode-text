#ifndef _TCP_CONNECTOR_HPP
#define _TCP_CONNECTOR_HPP

#ifndef _NETINET_IN_H
#include <netinet/in.h>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef _NETDB_H
#include <netdb.h>
#endif

#ifndef _ARPA_INET_H
#include <arpa/inet.h>
#endif

#ifndef _TCP_STREAM_HPP
#include "tcp_stream.hpp"
#endif

class TCP_Connector{
public:
  TCP_Stream* connect(const char* server, int port);
  
private:
  int resolveHostName(const char* host, struct in_addr* addr);
};

#endif /* End _TCP_CONNECTOR_HPP */
