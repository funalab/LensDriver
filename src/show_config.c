/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 00:06:30 +0900
 */
#include "lensdriver.h"

void show_config(int fd) {
  int size,sbit,pty;
  int ispeed,ospeed;
  struct termios term;

  /* Get and show current serial setting  */
  if(tcgetattr(fd, &term) < 0) {
    perror("Cannot get termios ");
    close(fd);
    exit(-1);
  }

  /* set the data length */
  size = term.c_cflag & CSIZE;

  printf("  Data length: ");
  if  (size == CS5) printf("5 bits/byte\n");
  else if  (size == CS6) printf("6 bits/byte\n");
  else if  (size == CS7) printf("7 bits/byte\n");
  else if  (size == CS8) printf("8 bits/byte\n");
  else printf("unknown bits/byte\n");

  /* stop bit */
  sbit = term.c_cflag & CSTOPB;

  if (sbit == 0) printf("  Size of stop bit: 1bit\n");
  else if (sbit == 1)  printf("  Size of stop bit: 2bit\n");

  /* parity */
  pty = term.c_cflag & PARENB;

  printf("  Checking and generating the parity: ");
  if(pty == 0)  printf("disable\n");
  else if(pty == 1) printf("enable\n");

  /* baud rate */
  ispeed = cfgetispeed(&term);
  ospeed = cfgetospeed(&term);

  printf("  Baud rate(Input)  : %d bps\n", ispeed);
  printf("  Baud rate(Output) : %d bps\n", ospeed);
}
