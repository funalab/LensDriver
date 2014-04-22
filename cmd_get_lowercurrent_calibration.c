/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:29:56 +0900
 */
#include "lensdriver.h"

int16_t cmd_get_lowercurrent_calibration(int fd) {
  uint8_t data[] = {'C','r','L','A','0','0','L','H'};
  int16_t value = (int16_t)cmd_get_calibration(fd, data, sizeof(data));
  if (DEBUG) {
    printf("Lower current limit: %d\n", value);
  }
  return value;
}
