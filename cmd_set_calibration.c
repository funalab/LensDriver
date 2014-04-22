/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 00:42:59 +0900
 */
#include "lensdriver.h"

uint16_t cmd_set_calibration(int fd, uint8_t* data, uint16_t current) {
  /* 
   * index:                    0   1   2   3   4   5   6   7
   * Send: uint8_t data[8] = {'C','w','M','A','x','x','L','H'}; 
   * Recv: uint8_t rbuf[9] = {'C','L','A','x','x','L','H','\r','\n'};
   */
  uint16_t crc;
  uint8_t rbuf[MAX_READ_BYTES];
  uint16_t value = 0;
  /* CRC */
  crc = getcrc(data, 6);
  data[6] = get_low8(crc);
  data[7] = get_high8(crc);
  set_uint8array16(current, &data[4]);

  /* Write and Read */
  write_device(fd, data, 8);
  read_device(fd, rbuf);

  /* uint8_t uint8_t => uint16_t */
  value = get_uint16(rbuf[3], rbuf[4]);
  return value;
}
