/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:33:17 +0900
 */
#include "lensdriver.h"

int cmd_set_sinusoidal(int fd) {
  uint8_t data[6] = {'M','w','S','A','L','H'}; 
  /* Send command to device */
  if (DEBUG) {
    printf("%sSet sinusoidal%s\n", GREEN, DEFAULT);
  }
  return cmd_set_mode(fd, data, sizeof(data));
}
