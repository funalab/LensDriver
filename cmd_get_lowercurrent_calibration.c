/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:09:25 +0900
 */
#include "lensdriver.h"

int16_t cmd_get_lowercurrent_calibration(int fd) {
  uint8_t data[] = {'C','r','L','A','0','0','L','H'};
  int16_t value = (int16_t)cmd_get_calibration(fd, data);
  if (DEBUG) {
    printf("Lower current limit: %d\n", value);
  }
  return value;
}
