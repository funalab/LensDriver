/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 19:07:59 +0900
 */
#include "lensdriver.h"

int cmd_run_sinusoidal(int fd, int16_t ucurrent, int16_t lcurrent, uint32_t mHz) {
  if (DEBUG) {
    printf("%sRun sinusoidal %d - %d %u [mHz]%s\n", GREEN, lcurrent, ucurrent, mHz, DEFAULT);
  }
  /* Set sinusoidal */
  if (cmd_set_sinusoidal(fd) == -1) {
    return -1;
  }
  /* Set Upper signal current */
  if (cmd_set_uppersignalcurrent(fd, ucurrent) == -1) {
    return -1;
  }
  /* Set Lower signal current */
  if (cmd_set_lowersignalcurrent(fd, lcurrent) == -1) {
    return -1;
  }
  /* Set Frequency in mHz */
  cmd_set_frequency(fd, mHz);

  return 0;
}
