/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 01:08:35 +0900
 */
#include "lensdriver.h"

int cmd_start(int fd) {
  uint8_t sbuf[] = {'S','t','a','r','t'};
  uint8_t rbuf[MAX_READ_BYTES];
  int nbytes;
  /* Start */
  write_device(fd, sbuf, sizeof(sbuf)/sizeof(sbuf[0]));
  nbytes = read_device(fd, rbuf);
  if (nbytes == -1) {
    return -1;
  }
  /* Check returned value with "Ready\r\n" */
  if (uint8ncmp(rbuf, (uint8_t*)ANS_READY, nbytes)) {
    return -1;
  }
  return 0;
}
