/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:10:47 +0900
 */
#include "lensdriver.h"

int cmd_set_current(int fd, uint32_t io) {
  /*
   * index:                    0   1   2   3   4
   * Send: uint8_t data[6] = {'A','x','x','L','H'};
   * Recv: none (or {'N','\r','\n'} on CRC error)
   */
  uint8_t data[5] = {'A','x','x','L','H'};
  uint16_t xi = 0, crc16 = 0;
 
  /* Check io */
  if (io > 280) {
    printf("%sAssigned current %d [mA] is too large.\nPlease assign a value less than 280 [mA].%s\n", RED, io, DEFAULT);
    return -1;
  }

  /* Set current */
  /* add get_maxhardwarecurrent and replaced with 293.0 */
  xi = roundf(4096.0*(double)io/((double)cmd_get_maxhardwarecurrent(fd) / 100.0));
  data[1] = get_high8(xi);
  data[2] = get_low8(xi);

  /* CRC */
  crc16 = getcrc(data, 3);
  data[3] = get_low8(crc16);
  data[4] = get_high8(crc16);

  /* Write */
  if (DEBUG) {
    printf("%sSet current to %d [mA]%s\n", GREEN, io, DEFAULT);
  }
  write_device(fd, data, 5);

  return 0;
}
