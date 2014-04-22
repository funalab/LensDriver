/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:31:28 +0900
 */
#include "lensdriver.h"

uint16_t cmd_set_maxhardwarecurrent(int fd, uint16_t maxcurrent) {
  uint8_t data[] = {'C','w','M','A',0,0,'L','H'};
  uint16_t value = cmd_set_calibration(fd, data, sizeof(data), maxcurrent);
  if (DEBUG) {
    printf("Maximum hardware current: %g [mA]\n", (double)value/100.0);
  }
  return value;
}
