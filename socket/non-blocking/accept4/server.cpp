#include <stdio.h>
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <fcntl.h>

#include <iostream>

using namespace std;
  
int main()  
{  
  int server_fd;  
  struct sockaddr_in addr;  
  struct sockaddr_in client;  
  int client_fd;  
  
  server_fd = socket(AF_INET, SOCK_STREAM, 0);  
  
  addr.sin_family = AF_INET;  
  addr.sin_port = htons(1337);
  addr.sin_addr.s_addr = INADDR_ANY;

  int optval = SOL_SOCKET;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0)
     perror("setsockopt SO_REUSEADDR");

  int flags = fcntl(server_fd, F_GETFL, 0);
  fcntl(server_fd, F_SETFL, flags | O_NONBLOCK); 

  bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));  
  
  listen(server_fd, 5);  
  
  socklen_t len = sizeof(client);

  while (true) {
    client_fd = accept4(server_fd, (struct sockaddr *)&client, &len, SOCK_NONBLOCK);

    if (client_fd < 0 && (errno == EAGAIN || errno == EINTR || errno == ECONNABORTED))
      continue;

    write(client_fd, "HELLO\n", 6);
    close(client_fd);  
    break;
  }
  
  close(server_fd);  

  return 0;  
}  
