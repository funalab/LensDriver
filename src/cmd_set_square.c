/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:33:32 +0900
 */
#include "lensdriver.h"

int cmd_set_square(int fd) {
  uint8_t data[6] = {'M','w','Q','A','L','H'}; 
  /* Send command to device */
  if (DEBUG) {
    printf("%sSet square%s\n", GREEN, DEFAULT);
  }
  return cmd_set_mode(fd, data, sizeof(data));
}
