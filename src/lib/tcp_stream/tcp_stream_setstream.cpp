#include "tcp_channel.hpp"

int TCP_Channel::setStream(TCP_Stream* stream){
  if( (NULL == stream) || (TCP_CHANNEL_WRAP_MODE != mode)){
    return FAIL;
  }
  this->wraped_stream = stream;

  return SUCCESS;
}
