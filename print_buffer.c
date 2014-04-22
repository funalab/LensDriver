/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:14:06 +0900
 */
#include "lensdriver.h"

void print_buffer(uint8_t *buf, int nbytes) {
  int i;
  for (i = 0; i < nbytes; i++) {
    if (buf[i] == '\r' && i == nbytes - 2) {
      printf("%s\\r%s", RED, DEFAULT);
    } else if (buf[i] == '\n' && i == nbytes - 1) {
      printf("%s\\n%s", RED, DEFAULT);
    } else if (isalpha(buf[i]) || isdigit(buf[i])) {
      printf("%s%c%s", RED, buf[i], DEFAULT);
    } else {
      printf("[%s%d%s]", BLUE, buf[i], DEFAULT);
    }
  }
  printf("\n");
}
