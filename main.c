/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:35:47 +0900
 */
#include "lensdriver.h"

int main(int argc, char* argv[]) {
  int fd;
  uint32_t mA = 200;   /* 200 mA */
  uint32_t mHz = 1000; /* 1 Hz */
  uint16_t ucurrent = 4000;  /* upper current for sinusoidal */
  uint16_t lcurrent = 0;     /* lower current for sinusoidal */
  /* Check arguments */
  if (argc < 2) {
    usage(argv);
    return 0;
  }
  /* Open device */
  fd = dev_open_setup(argv[1]);

  /* Start */
  if (cmd_start(fd) == -1) {
    safe_exit(fd);
  }
  /* Get upper current limit calibration */
  cmd_get_uppercurrent_calibration(fd);
  /* Get lower current limit calibration */
  cmd_get_lowercurrent_calibration(fd);
  /* Get maximum hardware current */
  cmd_get_maxhardwarecurrent(fd);

  /* Set Current in mA (0 to 280mA) */
  if (cmd_set_current(fd, mA) == -1) {
    safe_exit(fd);
  }
  sleep(5);

  /* Run sinusoidal */
  if (cmd_run_sinusoidal(fd, ucurrent, lcurrent, mHz) == -1) {
    safe_exit(fd);
  }
  sleep(10);

  /* Reset and close device */
  safe_exit(fd);
  return 0;
}