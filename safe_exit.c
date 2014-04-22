/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 17:47:15 +0900
 */
#include "lensdriver.h"

int safe_exit(int fd) {
  cmd_start(fd);
  close(fd);
  exit(0);
}
