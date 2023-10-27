/*
 * This program is licensed granted by STATE UNIVERSITY OF CAMPINAS - UNICAMP ("University")
 * for use of massccs-ompc software ("the Software") through this website
 * https://github.com/cces-cepid/massccs-ompc (the "Website").
 *
 * By downloading the Software through the Website, you (the "License") are confirming that you agree
 * that your use of the Software is subject to the academic license terms.
 *
 * For more information about massccs-ompc please contact: 
 * skaf@unicamp.br (Munir S. Skaf)
 * guido@unicamp.br (Guido Araujo)
 * samuelcm@unicamp.br (Samuel Cajahuaringa)
 * zanottol@unicamp.br (Leandro N. Zanotto)
 */

#include "headers/RandomNumber.h"

RandomNumber::RandomNumber(unsigned int seed) {
  // Initialize a Mersenne Twister - random number generator [0:1]
  std::mt19937::result_type mt_seed = seed;
  min = std::mt19937::min();
  max = std::mt19937::max();
  randomNumber = std::mt19937(mt_seed);
}

double RandomNumber::getRandomNumber() {
  return ((double)randomNumber() - min) / max;
}
