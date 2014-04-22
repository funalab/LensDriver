/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Mon, 17 Jun 2013 23:07:41 +0900
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
  return fd;
}
