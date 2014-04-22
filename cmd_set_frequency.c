/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:11:08 +0900
 */
#include "lensdriver.h"

int cmd_set_frequency(int fd, uint32_t freq) {
  uint8_t data[10] = {'P','w','F','A','y','y','y','y','L','H'}; 
  set_uint8array32(freq, &data[4]);
  cmd_set_signalproperty(fd, data);
  if (DEBUG) {
    printf("%sSet Frequency to : %u [mHz]%s\n", GREEN, freq, DEFAULT);
  }
  return 0;
}
