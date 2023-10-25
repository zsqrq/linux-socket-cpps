//
// Created by wz on 23-10-25.
//
#include "common/unp.h"

int sockfd_to_family(int sockfd) {
  struct sockaddr_storage ss;
  socklen_t len;
  len = sizeof (ss);
  if (getsockname(sockfd, (SA*) &ss, &len) < 0) {
    return (-1);
  }
  return (ss.ss_family);
}

int Sockfd_to_family(int sockfd) {
  int rc;
  if (rc = sockfd_to_family(sockfd) < 0) {
    err_sys("sockfd to family error");
  }
  return rc;
}