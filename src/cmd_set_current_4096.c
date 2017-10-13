/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:22:25 +0900
 */
#include "lensdriver.h"

int cmd_set_current_4096(int fd, uint16_t xi) {
  /*
   * index:                    0   1   2   3   4
   * Send: uint8_t data[5] = {'A','x','x','L','H'};
   * Recv: none (or {'N','\r','\n'} on CRC error)
   */
  uint8_t data[5] = {'A','x','x','L','H'};
  uint16_t crc16 = 0;
 
  /* Check io */
  if (xi > 4096) {
    printf("%sAssigned current %d [mA] is too large.\nPlease assign a value less than 4096.%s\n", RED, xi, DEFAULT);
    return -1;
  }

  /* Set current */
  /* add get_maxhardwarecurrent and replace with 293.0 */
 
  data[1] = get_high8(xi);
  data[2] = get_low8(xi);

  /* CRC */
  crc16 = getcrc(data, 3);
  data[3] = get_low8(crc16);
  data[4] = get_high8(crc16);

  /* Write */
  if (DEBUG) {
    printf("%sSet current to %d [mA]%s\n", GREEN, xi, DEFAULT);
  }
  write_device(fd, data, sizeof(data));

  return 0;
}
