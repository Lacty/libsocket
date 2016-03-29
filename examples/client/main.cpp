
//
// client test
//

#include "socket.hpp"


int main() {
  Socket client;

  client.connect("127.0.0.1", 12345); // set ip and port
  
  std::string str;
  
  // recv data
  client >> str;
  
  std::cout << str;
}