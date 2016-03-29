
//
// server test
//

#include "socket.hpp"


int main() {
  Socket server;
  Socket client;
  
  server.create();
  server.bind(12345); // set port
  server.listen();
  server.accept(client);
  
  std::string str = "hoge";
  
  // send data
  client << str;
}