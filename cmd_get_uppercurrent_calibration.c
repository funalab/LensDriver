/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 18:45:11 +0900
 */
#include "lensdriver.h"

int16_t cmd_get_uppercurrent_calibration(int fd) {
  uint8_t data[] = {'C','r','U','A','0','0','L','H'};
  int16_t value = (int16_t)cmd_get_calibration(fd, data);
  if (DEBUG) {
    printf("Upper current limit: %d\n", value);
  }
  return value;
}
