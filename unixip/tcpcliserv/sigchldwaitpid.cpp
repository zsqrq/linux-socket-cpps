//
// Created by wz on 23-10-26.
//
#include "common/unp.h"

void sig_chld(int sigo) {
  pid_t pid;
  int stat;
  while ((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
    printf("child %d terminated\n", pid);
  }
  return;
}
