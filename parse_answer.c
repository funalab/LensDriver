/*
 * Driver for Optotune LensDriver4
 * Author: Yuichiro Nakai <nakai@fun.bio.keio.ac.jp>
 *         Akira Funahashi <funa@bio.keio.ac.jp>
 * Last modified: Tue, 18 Jun 2013 04:38:41 +0900
 */
#include "lensdriver.h"

uint16_t Lranswer(uint8_t* Lranswer) {
  return get_limit(Lranswer);
}

uint16_t Lwanswer(uint8_t* Lwanswer) {
  return get_limit(Lwanswer);
}

uint16_t Mranswer(uint8_t* Mranswer) {
  return get_limit(Mranswer);
}

uint16_t Mwanswer(uint8_t* Mwanswer) {
  return get_limit(Mwanswer);
}

uint16_t Uranswer(uint8_t* Uranswer) {
  return get_limit(Uranswer);
}

uint16_t Uwanswer(uint8_t* Uwanswer) {
  return get_limit(Uwanswer);
}
