/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 00:30:58 +0900
 */
#include "lensdriver.h"

int write_device(int fd, uint8_t* cmd, int nbytes) {
  int count;
  /* Write to device */
  if (DEBUG) {
    printf("Write: ");
    print_buffer(cmd, nbytes);
  }
  count = write(fd, cmd, nbytes);
  if (count < 0) {
    fprintf(stderr, "write() of %d bytes failed. %s\n", nbytes, strerror(errno));
    close(fd);
    exit(-1);
  }
  return count;
}
