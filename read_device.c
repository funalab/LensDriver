/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 01:57:15 +0900
 */
#include "lensdriver.h"

uint8_t* read_device(int fd, uint8_t *rbuf, int nbytes) {
  /* Blocking read for usual communication */
  int rbytes;
  int count = 0;
  uint8_t t;
  /* Read from device */
  while(count < nbytes) {
    rbytes = read(fd, &t, 1);
    if (rbytes > 0) {
      rbuf[count] = t;
      count ++;
    }
  }
  if (DEBUG) {
    printf(" Read: ");
    print_buffer(rbuf, nbytes);
  }
  return rbuf;
}

int read_device_nb(int fd, uint8_t *rbuf) {
  /* Non-blocking read for junk packets */
  int nbytes = 0;
  int nfds;
  fd_set readfds;
  struct timeval tv;
  /* Check fd for read */
  FD_ZERO(&readfds);
  FD_SET(fd, &readfds);
  /* Set timeout (less than 1 sec for this code) */
  tv.tv_sec = 0;
  tv.tv_usec = TIME_OUT_USEC;
  /* Call select and wait until it reaches the timeout */
  nfds = select(fd+1, &readfds, NULL, NULL, &tv);

  if (nfds == 0) {         /* time out */
    /* printf("%sTimeout!%s\n", YELLOW, DEFAULT); */
    return 0;
  } else if (nfds == -1) { /* error */
    printf("%sRead failed!%s\n", RED, DEFAULT);
    return -1;
  } else {
    if (FD_ISSET(fd, &readfds)) {
      nbytes = read(fd, rbuf, MAX_READ_BYTES);
    }
    if (DEBUG) {
      printf(" Read: ");
      print_buffer(rbuf, nbytes);
    }
  }
  return nbytes;
}
