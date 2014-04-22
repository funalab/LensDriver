/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:12:17 +0900
 */
#include "lensdriver.h"

int cmd_set_uppersignalcurrent(int fd, int16_t current) {
  uint8_t data[10] = {'P','w','U','A','y','y','d','d','L','H'}; 
  if (current > 4095 || current < -4095) {
    printf("%sSet Upper signal current failed. Current is : %d%s\n", RED, current, DEFAULT);
    return -1;
  }
  if (DEBUG) {
    printf("%sSet Upper signal current to : %d%s\n", GREEN, current, DEFAULT);
  }
  set_uint8array16(current, &data[4]);
  cmd_set_signalproperty(fd, data);
  return 0;
}
