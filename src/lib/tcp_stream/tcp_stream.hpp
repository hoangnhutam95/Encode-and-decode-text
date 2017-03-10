#ifndef _TCP_STREAM_HPP
#define _TCP_STREAM_HPP

#ifndef _SYS_TYPES_H
#include <sys/types.h>
#endif

#ifndef _SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifndef _ARPA_INET_H
#include <arpa/inet.h>
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

#ifndef _GLIBCXX_STRING
#include <string>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef SUCCESS
#define SUCCESS 1
#endif

#ifndef FAIL
#define FAIL 0
#endif

using namespace std;

class TCP_Stream{
  int m_sd;
  string m_peerIP;
  int m_peerPort;
private:
  TCP_Stream();
  TCP_Stream(int sd, struct sockaddr_in* address);
  TCP_Stream(const TCP_Stream& stream);
public:
  friend class TCP_Acceptor;
  friend class TCP_Connector;

  ~TCP_Stream(){
      close(m_sd);
  }

  ssize_t send(const char* buffer, size_t len);
  ssize_t receive(char* buffer, size_t len);
  
  int sendFile(char* path);
  int receiveFile(char* path);

  int sendDataSegment(char* data_segment_ptr, long leng);
  int receiveDataSegment(char* data_segment_ptr, long *leng);

  string getPeerIP();
  int getPeerPort();

};

#endif /* End _TCP_STREAM_HPP */
