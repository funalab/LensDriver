/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:45:39 +0900
 */
#include "lensdriver.h"

int cmd_set_dc(int fd) {
  uint8_t data[6] = {'M','w','D','A','L','H'}; 
  /* Send command to device */
  if (DEBUG) {
    printf("%sSet dc%s\n", GREEN, DEFAULT);
  }
  return cmd_set_mode(fd, data);
}
