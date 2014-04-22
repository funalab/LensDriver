/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:45:49 +0900
 */
#include "lensdriver.h"

int cmd_run_square(int fd, int16_t ucurrent, int16_t lcurrent, uint32_t mHz) {
  if (DEBUG) {
    printf("%sRun square %d - %d %u [mHz]%s\n", GREEN, lcurrent, ucurrent, mHz, DEFAULT);
  }
  /* Set square */
  if (cmd_set_square(fd) == -1) {
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
