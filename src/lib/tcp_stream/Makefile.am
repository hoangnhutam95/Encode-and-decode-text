AM_CXXFLAGS = -I ../lib -include ../../../config.h -std=gnu++11

#### Lib TCP-Channel: TCP-Stream.
lib_tcp_channel_stream = tcp_stream.hpp
lib_tcp_channel_stream += tcp_stream.cpp
lib_tcp_channel_stream += tcp_stream_sendfile.cpp
lib_tcp_channel_stream += tcp_stream_receivefile.cpp
lib_tcp_channel_stream += tcp_stream_senddatasegment.cpp
lib_tcp_channel_stream += tcp_stream_receivedatasegment.cpp


#### Lib TCP-Channel: TCP-Connector.
lib_tcp_channel_connector = tcp_connector.hpp
lib_tcp_channel_connector += tcp_connector_connect.cpp
lib_tcp_channel_connector += tcp_connector_resolvehostname.cpp

#### Lib TCP-Channel: TCP-Acceptor.
lib_tcp_channel_acceptor = tcp_acceptor.hpp
lib_tcp_channel_acceptor += tcp_acceptor_accept.cpp
lib_tcp_channel_acceptor += tcp_acceptor.cpp
lib_tcp_channel_acceptor += tcp_acceptor_start.cpp

#### Lib TCP-Stream: All files.
lib_tcp_stream_files = $(lib_tcp_channel_stream) + $(lib_tcp_channel_acceptor) + $(lib_tcp_channel_connector)

# Librarys when buil program.
noinst_LIBRARIES = lib_tcp_stream_temp.a
lib_tcp_stream_temp_a_SOURCES = $(lib_tcp_stream_files)

# Install headers
otherincludedir = $(includedir)/andromeda
otherinclude_HEADERS = tcp_acceptor.hpp tcp_connector.hpp tcp_stream.hpp

# Install librarys
otherlibdir = $(libdir)/andromeda
otherlib_LIBRARIES = lib_tcp_stream.a
lib_tcp_stream_a_SOURCES = $(lib_tcp_stream_files)
