#include "tcp_stream.hpp"

int TCP_Stream::sendDataSegment(char* data_segment_ptr, long leng){
  long leng_sended, leng_temp, offset;
  char* ptr;

  leng_sended = 0;
  offset = 0;
  ptr = (char*)&leng;
  leng_temp = 0;

  // Send infomation about leng of datasegment.
  leng_temp = sizeof(long);
  leng_sended = this->send( (char*)&leng, leng_temp);
  if( leng_sended != sizeof(long)){
    printf("Error leng infomation!\n");
    return FAIL;
  }
  // Send datasegment.
  leng_temp = leng;
  leng_sended = 0;
  offset = 0;
  leng_sended += this->send( &(data_segment_ptr[offset]), leng_temp);
  offset = leng_sended;
  leng_temp -= leng_sended;
  while( leng_sended < leng_temp){
    leng_sended += this->send( &(data_segment_ptr[offset]), leng_temp);
    offset = leng_sended;
    leng_temp -= leng_sended;
  }
  return SUCCESS;  
}
