#include "tcp_stream.hpp"

int TCP_Stream::receiveDataSegment(char* data_segment_ptr, long* leng){
  long leng_received, leng_temp, offset;
  char* ptr;

  leng_received = 0;
  offset = 0;
  ptr = (char*)leng;
  *leng = 0;
  leng_temp = 0;

  // Receive infomation about leng of datasegment.
  leng_temp = sizeof(long);
  leng_received = this->receive( &(ptr[offset]), leng_temp);
  if( leng_received != sizeof(long)){
    printf("Error size segment!\n");
    return FAIL;
  }

  // Receive datasegment.
  leng_temp = *leng;
  leng_received = 0;
  offset = 0;
  leng_received += this->receive( &(data_segment_ptr[offset]), leng_temp);
  offset = leng_received;
  leng_temp -= leng_received;
  //printf("Received all %lu bytes!\n", leng_received);
  while( leng_received < leng_temp){
    leng_received += this->receive( &(data_segment_ptr[offset]), leng_temp);
    offset = leng_received;
  }
  return SUCCESS;
}
