/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 00:36:14 +0900
 */
#include "lensdriver.h"

uint8_t* read_device(int fd, uint8_t *rbuf, int nbytes) {
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
