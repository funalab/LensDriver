/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 00:28:25 +0900
 */
#include "lensdriver.h"

int uint8ncmp(uint8_t* s, uint8_t* t, int n) {
  int i;
  for (i = 0; i < n; i++) {
    if (s[i] - t[i] != 0) {
      return s[i] - t[i];
    }
  }
  return 0;
}
