/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 01:57:56 +0900
 */
#include "lensdriver.h"

int clear_recv_buffer(int fd) {
  int nbytes;
  uint8_t rbuf[MAX_READ_BYTES];
  /* Clear receive buffer because of junk  packet */
  nbytes = read_device_nb(fd, rbuf);
  if (nbytes != -1 && DEBUG) {
    printf("%sCleared receive buffer%s\n", GREEN, DEFAULT);
  }
  return nbytes;
}
