/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 02:25:39 +0900
 */
#include "lensdriver.h"

uint16_t crc16_update(uint16_t crc, uint8_t a) {
  int i;
  crc ^= a;
  for (i = 0; i < 8; ++i) {
    if (crc & 1)
      crc = (crc >> 1) ^ 0xA001;
    else
      crc = (crc >> 1);
  }
  return crc; 
}

uint16_t getcrc(uint8_t *data, int nbytes) {
  int i;
  uint16_t crc = 0;
  for (i = 0; i < nbytes; i++) {
    crc = crc16_update(crc, data[i]);
  }
  return crc; /* returns checksum over all elements */
}

uint8_t get_low8(uint16_t crc16) {
  return crc16 & 0xFF;
}

uint8_t get_high8(uint16_t crc16) {
  return crc16 >> 8;
}

uint16_t get_uint16(uint8_t high, uint8_t low) {
  uint16_t uint16 = ((uint16_t)high << 8) | low;
  return uint16;
}

uint8_t* set_uint8array16(uint16_t uint16, uint8_t* array) {
  array[0] = (uint16 >>  8) & 0xFF;
  array[1] = uint16 & 0xFF;
  return array;
}

uint8_t* set_uint8array32(uint32_t uint32, uint8_t* array) {
  array[0] = (uint32 >> 24) & 0xFF;
  array[1] = (uint32 >> 16) & 0xFF;
  array[2] = (uint32 >>  8) & 0xFF;
  array[3] = uint32 & 0xFF;
  return array;
}

uint16_t get_limit(uint8_t* answer) {
  uint16_t limit;
  limit = answer[3];
  limit = limit << 8;
  limit = limit ^ answer[4];
  return limit;
}

uint16_t checkcrc(void) {
  int i;
  uint16_t crc = 0;
  uint8_t data[] = {'C', 'r', 'U', 'A', '0', '0'};
  for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    crc = crc16_update(crc, data[i]);
    printf("%c:%d\n", data[i], crc);
  }
  printf("\n");
  return crc; /* returns checksum over all elements */
}

int main2(int argc, char const* argv[]) {
  uint16_t crc16;
  uint8_t data[] = {'C', 'r', 'U', 'A', '0', '0'};
  /* crc16 = checkcrc(); */
  crc16 = getcrc(data, 6);
  printf("%x [%c]\n", get_low8(crc16), get_low8(crc16));
  printf("%x [%c]\n", get_high8(crc16), get_high8(crc16));
  return 0;
}

