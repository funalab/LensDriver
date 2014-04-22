/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:34:57 +0900
 */
#include "lensdriver.h"

int cmd_set_signalproperty(int fd, uint8_t* data, int nbytes) {
  /* 
   * index:                     0   1   2   3   4   5   6   7   8   9
   * Send: uint8_t data[10] = {'P','w','F','A','y','y','y','y','L','H'}; 
   * Recv: none;
   */
  uint16_t crc;
  /* CRC */
  crc = getcrc(data, 8);
  data[8] = get_low8(crc);
  data[9] = get_high8(crc);

  /* Write */
  write_device(fd, data, nbytes);

  return 0;
}
