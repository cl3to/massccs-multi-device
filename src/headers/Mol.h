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

#ifndef MASSCCS_OMPC_V1_MOL_H
#define MASSCCS_OMPC_V1_MOL_H

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
class Mol {

public:
  Mol(int _natoms, double *_x, double *_y, double *_z, double *_eps, double *_sig, double *_q);

  int natoms;
  double *x;
  double *y;
  double *z;
  double *q;
  double *eps;
  double *sig;

};
#pragma omp end declare target

#endif

