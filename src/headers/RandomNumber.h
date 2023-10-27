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

#ifndef MASSCCS_OMPC_V1_RANDOMNUMBER_H
#define MASSCCS_OMPC_V1_RANDOMNUMBER_H

#include <random>

class RandomNumber {
private:
  unsigned long min, max;
  std::mt19937 randomNumber;

public:
  explicit RandomNumber(unsigned int seed);

  double getRandomNumber();
};

#endif
