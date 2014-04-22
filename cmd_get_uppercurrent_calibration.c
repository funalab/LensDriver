/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:30:38 +0900
 */
#include "lensdriver.h"

int16_t cmd_get_uppercurrent_calibration(int fd) {
  uint8_t data[] = {'C','r','U','A','0','0','L','H'};
  int16_t value = (int16_t)cmd_get_calibration(fd, data, sizeof(data));
  if (DEBUG) {
    printf("Upper current limit: %d\n", value);
  }
  return value;
}
