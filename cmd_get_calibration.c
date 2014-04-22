/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 17:51:11 +0900
 */
#include "lensdriver.h"

uint16_t cmd_get_calibration(int fd, uint8_t* data) {
  /* 
   * index:                    0   1   2   3   4   5   6   7
   * Send: uint8_t data[8] = {'C','r','M','A','0','0','L','H'}; 
   * Recv: uint8_t rbuf[9] = {'C','U','A','y','y','L','H','\r','\n'};
   */
  uint16_t crc;
  uint8_t rbuf[9];
  uint16_t value = 0;
  /* CRC */
  crc = getcrc(data, 6);
  data[6] = get_low8(crc);
  data[7] = get_high8(crc);

  /* Write and Read */
  write_device(fd, data, 8);
  read_device(fd, rbuf, sizeof(rbuf)/sizeof(rbuf[0]));

  /* uint8_t uint8_t => uint16_t */
  value = get_uint16(rbuf[3], rbuf[4]);
  return value;
}
