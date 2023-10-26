//
// Created by wz on 23-10-26.
//
#include "common/unp.h"

void sig_chld(int signo) {
  pid_t pid;
  int stat;

  pid = wait(&stat);
  printf("child %d terminated\n", pid);
  return;
}
