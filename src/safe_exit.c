/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 01:09:58 +0900
 */
#include "lensdriver.h"

int safe_exit(int fd) {
  clear_recv_buffer(fd);
  cmd_start(fd);
  clear_recv_buffer(fd);
  close(fd);
  exit(0);
}
