/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:30:17 +0900
 */
#include "lensdriver.h"

uint16_t cmd_get_maxhardwarecurrent(int fd) {
  uint8_t data[] = {'C','r','M','A','0','0','L','H'};
  uint16_t value = cmd_get_calibration(fd, data, sizeof(data));
  if (DEBUG) {
    printf("Maximum hardware current: %g [mA]\n", (double)value/100.0);
  }
  return value;
}
