/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Mon, 17 Jun 2013 23:17:32 +0900
 */
#include "lensdriver.h"

int usage(char* argv[]) {
  printf("Usage: %s /dev/tty.usbmodem1411\n", argv[0]);
  return 0;
}
