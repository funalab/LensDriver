/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:11:19 +0900
 */
#include "lensdriver.h"

int cmd_set_lowersignalcurrent(int fd, int16_t current) {
  uint8_t data[10] = {'P','w','L','A','y','y','d','d','L','H'}; 
  if (current > 4095 || current < -4095) {
    printf("%sSet Lower signal current failed. Current is : %d%s\n", RED, current, DEFAULT);
    return -1;
  }
  set_uint8array16(current, &data[4]);
  cmd_set_signalproperty(fd, data);
  if (DEBUG) {
    printf("%sSet Lower signal current to : %d%s\n", GREEN, current, DEFAULT);
  }
  return 0;
}
