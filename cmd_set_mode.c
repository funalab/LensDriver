/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:11:48 +0900
 */
#include "lensdriver.h"

int cmd_set_mode(int fd, uint8_t* data) {
  /* 
   * index:                    0   1   2   3   4   5
   * Send: uint8_t data[6] = {'M','w','S','A','L','H'}; 
   * Recv: uint8_t rbuf[7] = {'M','S','A','L','H','\r','\n'};
   */
  uint16_t crc;
  uint8_t rbuf[7];
  uint8_t ans[7];
  /* CRC */
  crc = getcrc(data, 4);
  data[4] = get_low8(crc);
  data[5] = get_high8(crc);

  /* Write and Read */
  write_device(fd, data, 6);
  read_device(fd, rbuf, sizeof(rbuf)/sizeof(rbuf[0]));

  /* Prepare expected answer from device */
  ans[0] = data[0];
  ans[1] = data[2];
  ans[2] = data[3];
  ans[3] = get_low8(getcrc(data,3));
  ans[4] = get_high8(getcrc(data,3));
  ans[5] = '\r';
  ans[6] = '\n';
  /* Check returned value with expected answer */
  if (!uint8ncmp(rbuf, ans, sizeof(rbuf)/sizeof(rbuf[0]))) {
    return -1;
  }
  return 0;
}