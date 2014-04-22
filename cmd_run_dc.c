/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:45:52 +0900
 */
#include "lensdriver.h"

int cmd_run_dc(int fd, int16_t ucurrent, int16_t lcurrent) {
  if (DEBUG) {
    printf("%sRun dc %d - %d %s\n", GREEN, lcurrent, ucurrent, DEFAULT);
  }
  /* Set dc */
  if (cmd_set_dc(fd) == -1) {
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
  return 0;
}
