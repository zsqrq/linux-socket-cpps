//
// Created by wz on 23-11-3.
//
#include <limits.h>
#include <limits>
#include "common/unp.h"

int main(int argc, char** argv) {
  int i, maxi, listenfd, connfd,sockfd;
  int nready;
  ssize_t n;
  char buf[MAXLINE];
  socklen_t clilen;
  struct pollfd client[FOPEN_MAX];
  struct sockaddr_in cliaddr,servaddr;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(SERV_PORT);

  Bind(listenfd, (SA*) &servaddr, sizeof(servaddr));
  Listen(listenfd, LISTENQ);

  client[0].fd = listenfd;
  client[0].events = POLLRDNORM;

  for (i = 0; i < FOPEN_MAX; ++i) {
    client[i].fd = -1;
  }
  maxi = 0;

  for (;;) {
    nready = Poll(client, maxi+1, INFTIM);

    if (client[0].revents & POLLRDNORM) {
      clilen = sizeof(cliaddr);
      connfd = accept(listenfd, (SA*) &cliaddr, &clilen);
#ifdef NOTDEF
      printf("new client : %s\n", Sock_ntop((SA*) &cliaddr, clilen));
#endif
      for (i = 0; i < FOPEN_MAX; ++i) {
        if (client[i].fd < 0) {
          client[i].fd = connfd;
          break;
        }
        if (i == FOPEN_MAX) {
          err_quit("too many clients");
        }
        client[i].events = POLLRDNORM;
        if (i > maxi) {
          maxi = i;
        }
        if (--nready <= 0) {
          continue;
        }
      }

      for (i = 1; i <= maxi; ++i) {
        if ((sockfd = client[i].fd) < 0) {
          continue;
        }
        if (client[i].revents & (POLLRDNORM | POLLERR)) {
          if ((n = read(sockfd, buf, MAXLINE)) < 0) {
            if (errno == ECONNRESET) {
#ifdef NOTDEF
              printf("client [%d] aborted connection \n", i);
#endif
              Close(sockfd);
              client[i].fd = -1;
            } else {
              err_sys("read error");
            }
          } else if (n == 0) {
#ifdef	NOTDEF
            printf("client[%d] closed connection\n", i);
#endif
            Close(sockfd);
            client[i].fd = -1;
          } else {
            Writen(sockfd, buf, n);
          }
          if (--nready <= 0) break;
        }
      }
    }
  }
  return 0;
}
