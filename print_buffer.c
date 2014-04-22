/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 01:35:51 +0900
 */
#include "lensdriver.h"

void print_buffer(uint8_t *buf, int nbytes) {
  int i;
  for (i = 0; i < nbytes; i++) {
    if (buf[i] == '\r') {
      printf("%s\\r%s", RED, DEFAULT);
    } else if (buf[i] == '\n') {
      printf("%s\\n%s", RED, DEFAULT);
    } else if (isalpha(buf[i]) || isdigit(buf[i])) {
      printf("%s%c%s", RED, buf[i], DEFAULT);
    } else {
      printf("[%s%d%s]", BLUE, buf[i], DEFAULT);
    }
  }
  printf("\n");
}
