/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:37:14 +0900
 */
#include "lensdriver.h"

int cmd_start(int fd) {
  uint8_t sbuf[] = {'S','t','a','r','t'};
  uint8_t rbuf[7];
  /* Start */
  write_device(fd, sbuf, sizeof(sbuf)/sizeof(sbuf[0]));
  read_device(fd, rbuf, sizeof(rbuf)/sizeof(rbuf[0]));
  /* Check returned value with "Ready\r\n" */
  if (uint8ncmp(rbuf, (uint8_t*)ANS_READY, sizeof(rbuf)/sizeof(rbuf[0]))) {
    return -1;
  }
  return 0;
}
