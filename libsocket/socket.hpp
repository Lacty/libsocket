
/*-------------------------------

  socket library
 
  TCP socket connections
  supporting Mac
  
  Copyright (C) 2016/03/29 @Lacty
 
-------------------------------*/


#pragma once

#include <iostream>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


class Socket {
private:
  int sock_;
  sockaddr_in addr_;
  
  const int LISTEN_NUM    = 5;
  const int BUFFER_SIZE   = 1024;
  
public:
  Socket();
  ~Socket();
  
  // server func
  bool create();
  bool bind(const int port);
  bool listen();
  bool accept(Socket &connect);
  
  // client func
  bool connect(const std::string& address, const int port);
  
  // data transmission
  bool recv(std::string& data);
  bool send(const std::string& data);
  std::string recv();
  
  // check if socket is valid
  bool is_valid();
  
  // operators
  void operator >> (std::string& data);
  void operator << (const std::string& data);
};