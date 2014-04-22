/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 00:06:43 +0900
 */
#include "lensdriver.h"

void config_serial(int fd) {
  struct termios term;

  if (tcgetattr(fd, &term) < 0) {
    perror("ERROR: Cannot get termios ");
    close(fd);
    exit(-1);
  }

  /*** configure the serial port ***/
  /* set baud rate to 115200bps */
  cfsetispeed(&term, B115200);
  cfsetospeed(&term, B115200);

  /* enable to recieve characters */
  term.c_cflag |= (CLOCAL | CREAD);

  /* data length */
  term.c_cflag &= ~CSIZE;  /* zero out the bits */
  term.c_cflag |= CS8;     /* set 8 bits/byte */

  /* set parity checking to disable */
  term.c_cflag &= ~PARENB;

  /* set the stop bit to 1 */
  term.c_cflag &= ~CSTOPB;  /* zero out the bits */

  /* Hardware flow control */
  /* term.c_cflag |= CRTSCTS;    [> Also called CRTSCTS <] */
  /* Disable Hardware flowcontrol */
  /* term.c_cflag &= ~CNEW_RTSCTS;  -- not supported */

  /* Enable Raw Input */
  term.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

  /* Disable Software Flow control */
  term.c_iflag &= ~(IXON | IXOFF | IXANY);

  /* Chose raw (not processed) output */
  term.c_oflag &= ~OPOST;

  /* Set the new options for the port */
  if(tcsetattr(fd, TCSANOW, &term) == -1) {
    perror("Cannot set termios ");
    exit(-1);
  }
  if (DEBUG) {
    printf("tcsetattr: success\n");
  }
}

