//
// Created by wz on 23-10-23.
//
#include "sock/ourhdr..h"
#include "common/unp.h"

ssize_t						/* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
  size_t		nleft, nwritten;
  const char	*ptr;

  ptr = static_cast<const char *>(vptr);	/* can't do pointer arithmetic on void* */
  nleft = n;
  while (nleft > 0) {
    if ( (nwritten = write(fd, ptr, nleft)) <= 0)
      return(nwritten);		/* error */

    nleft -= nwritten;
    ptr   += nwritten;
  }
  return(n);
}

