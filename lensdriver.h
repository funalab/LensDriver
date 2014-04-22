/*
 * Driver for Optotune LensDriver4
 * Author: Akira Funahashi <funa@bio.keio.ac.jp>
 *         Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 * Last modified: Tue, 22 Apr 2014 23:37:32 +0900
 */
#ifndef __LENSDRIVER_H__
#define __LENSDRIVER_H__

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#define false 0
#define true 1

#define DEBUG 1
#define MAX_READ_BYTES 10

#define ANS_READY     "Ready\r\n"
#define ANS_CRC_ERROR "N\r\n"

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define DEFAULT "\x1b[39m"
#define UNDER_LINE   "\x1b[4m"
#define BOLD         "\x1b[1m"
#define FONT_DEFAULT "\x1b[0m"

/** Handling bits and bytes **/
uint16_t checkcrc(void);
uint16_t getcrc(uint8_t *data, int nbytes);
uint8_t get_low8(uint16_t crc16);
uint8_t get_high8(uint16_t crc16);
uint16_t get_uint16(uint8_t high, uint8_t low);
uint8_t* set_uint8array32(uint32_t uint32, uint8_t* array);
uint8_t* set_uint8array16(uint16_t uint16, uint8_t* array);
uint16_t get_limit(uint8_t* answer);
uint16_t crc16_update(uint16_t crc, uint8_t a);
int uint8ncmp(uint8_t* s, uint8_t* t, int n);

/** Low level API **/
uint8_t* read_device(int fd, uint8_t* rbuf, int nbytes);
int write_device(int fd, uint8_t* cmd, int nbytes);
void show_config(int fd);
void config_serial(int fd);
int cmd_set_mode(int fd, uint8_t* data);
int cmd_set_signalproperty(int fd, uint8_t* data);
uint16_t cmd_get_calibration(int fd, uint8_t* data);
uint16_t cmd_set_calibration(int fd, uint8_t* data, uint16_t current);
uint16_t Lranswer(uint8_t* Lranswer);
uint16_t Lwanswer(uint8_t* Lwanswer);
uint16_t Mranswer(uint8_t* Mranswer);
uint16_t Mwanswer(uint8_t* Mwanswer);
uint16_t Uranswer(uint8_t* Uranswer);
uint16_t Uwanswer(uint8_t* Uwanswer);

/** High level API **/
int dev_open_setup(char* device_file);
int safe_exit(int fd);
int cmd_start(int fd);
int16_t cmd_get_uppercurrent_calibration(int fd);
int16_t cmd_get_lowercurrent_calibration(int fd);
uint16_t cmd_get_maxhardwarecurrent(int fd);
uint16_t cmd_set_maxhardwarecurrent(int fd, uint16_t maxcurrent);
int cmd_set_current(int fd, uint32_t io);
int cmd_set_current_4096(int fd, uint16_t xi);
int cmd_set_frequency(int fd, uint32_t freq);
int cmd_set_uppersignalcurrent(int fd, int16_t current);
int cmd_set_lowersignalcurrent(int fd, int16_t current);
int cmd_set_sinusoidal(int fd);
int cmd_set_square(int fd);
int cmd_set_triangular(int fd);
int cmd_set_dc(int fd);
int cmd_run_sinusoidal(int fd, int16_t ucurrent, int16_t lcurrent, uint32_t mHz);
int cmd_run_square(int fd, int16_t ucurrent, int16_t lcurrent, uint32_t mHz);
int cmd_run_triangular(int fd, int16_t ucurrent, int16_t lcurrent, uint32_t mHz);
int cmd_run_dc(int fd, int16_t ucurrent, int16_t lcurrent);
/** Utility function **/
void print_buffer(uint8_t *buf, int nbytes);
int usage(char *argv[]);

#endif
