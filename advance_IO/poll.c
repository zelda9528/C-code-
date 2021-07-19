#include <poll.h> 
#include <unistd.h> 
#include <stdio.h>
#define MAX_COUNT 10
int main() {
  struct pollfd poll_fd[MAX_COUNT];   
  poll_fd[0].fd = 0;
  poll_fd[0].events = POLLIN;   
  int nfds=1;

  for (;;) {
  int ret = poll(poll_fd, nfds, 3000);
    if (ret < 0) {
      perror("poll");  
      usleep(1000);
      continue;
    }

  if (ret == 0) {
        printf("poll timeout\n");    
        continue;
  
    }
 
  for(int i=0;i<nfds;i++)
  {
    if (poll_fd[i].revents & POLLIN) {   
      printf("fd:%d 就绪了\n",poll_fd[i].fd);
      char buf[1024] = {0};
      read(0, buf, sizeof(buf) - 1);  
      printf("stdin:%s", buf);
    }
  } 
}

}
