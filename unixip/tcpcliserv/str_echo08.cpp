//
// Created by wz on 23-10-27.
//
#include "common/unp.h"

void str_echo(int sockfd) {
  long arg1, arg2;
  ssize_t n;
  char line[MAXLINE];

  for (;;) {
    if ((n = Readline(sockfd, line, MAXLINE)) == 0) {
      return;
    }
    if (sscanf(line, "%ld%ld", &arg1, &arg1) == 0) {
      snprintf(line, sizeof(line), "%ld\n", arg1+arg2);
    } else {
      snprintf(line, sizeof(line),"input error \n");
    }
    n = strlen(line);
    Writen(sockfd,line,n);
  }

}