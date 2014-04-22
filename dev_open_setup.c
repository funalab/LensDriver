/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Wed, 23 Apr 2014 01:01:39 +0900
 */
#include "lensdriver.h"

int dev_open_setup(char* device_file) {
  int fd;
  if((fd = open(device_file, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
    perror("dev_open_setup(): Unable to open device file ");
    exit(-1);
  }
  fcntl(fd, F_SETFL, FNDELAY);
  /* Setup device */
  printf("***********  Default Serial Setting  **********\n");
  show_config(fd);
  config_serial(fd);
  printf("***********  Current Serial Setting  **********\n");
  show_config(fd);
  printf("***********************************************\n");
  /* Clear receive buffer before we start */
  clear_recv_buffer(fd);
  return fd;
}
