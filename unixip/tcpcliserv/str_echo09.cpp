//
// Created by wz on 23-10-27.
//
#include "common/unp.h"
#include "sum.h"

void str_echo(int sockfd) {
  ssize_t n;
  struct args args;
  struct result result;

  for (;;) {
    if ((n = Readn(sockfd, &args, sizeof(args))) == 0) {
      return;
    }
    result.sum = args.arg1 + args.arg2;
    Writen(sockfd, &result, sizeof(result));
  }
}
