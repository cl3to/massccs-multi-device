/*
 * This program is licensed granted by STATE UNIVERSITY OF CAMPINAS - UNICAMP ("University")
 * for use of MassCCS software ("the Software") through this website
 * https://github.com/cces-cepid/MassCCS (the "Website").
 *
 * By downloading the Software through the Website, you (the "License") are confirming that you agree
 * that your use of the Software is subject to the academic license terms.
 *
 * For more information about MassCCS please contact: 
 * skaf@unicamp.br (Munir S. Skaf)
 * guido@unicamp.br (Guido Araujo)
 * samuelcm@unicamp.br (Samuel Cajahuaringa)
 * danielzc@unicamp.br (Daniel L. Z. Caetano)
 * zanottol@unicamp.br (Leandro N. Zanotto)
 */

#ifndef MASSCCS_V1_GASPROBE_H
#define MASSCCS_V1_GASPROBE_H

#include <cmath>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include "omp.h"

using namespace std;

#pragma omp declare target
class GasProbe {
private:
  void gas_properties();
  int gas_buffer_flag;
public:
  GasProbe(int _gas_buffer_flag);
  unsigned int natoms;
  unsigned int datoms;
  int id;
  string *atomName;
  double *x;
  double *y;
  double *z;
  double *q;
  double *m;
  double *eps;
  double *sig;
  double *vx;
  double *vy;
  double *vz;
  double mass;
  double rcm[3];
  double vcm[3];
  string gas_type;
  double d;
};
#pragma omp end declare target

#endif // MASSCCS_V1_GASPROBE_H
