//
// Created by wz on 23-10-25.
//
#include "common/unp.h"

ssize_t						/* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
  size_t		nleft;
  ssize_t		nwritten;
  const char	*ptr;

  ptr = static_cast<const char*>(vptr);
  nleft = n;
  while (nleft > 0) {
    if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
      if (nwritten < 0 && errno == EINTR)
        nwritten = 0;		/* and call write() again */
      else
        return(-1);			/* error */
    }

    nleft -= nwritten;
    ptr   += nwritten;
  }
  return(n);
}
/* end writen */

void
Writen(int fd, void *ptr, size_t nbytes)
{
  if (writen(fd, ptr, nbytes) != nbytes)
    err_sys("writen error");
}

