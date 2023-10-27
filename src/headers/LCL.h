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

#ifndef MASSCCS_OMPC_V1_LCL_H
#define MASSCCS_OMPC_V1_LCL_H

#include <cmath>
#include <vector>
#include <iostream>
#include "omp.h"

using namespace std;

#pragma omp declare target
class LCL {
private:
  double corner[3];
  double lj_cutoff;
  double skin;
  int Nx, Ny, Nz;
  double lx, ly, lz;
  int *n1_cells;
  int *n2_cells;
  int *atoms_cell;
  int *n1_cells_ids;
  int *n2_cells_ids;
  int *ids;
  
  void calculateNeighborsVectors(); 
  void print();

public:
  LCL(int _Ncells, int *_n1_cells, int *_n2_cells, int *_atoms_cell, int *_n1_cells_ids, int *_n2_cells_ids, int *_ids,
         double _lj_cutoff, double _skin, double _lx, double _ly, double _lz, int _Nx, int _Ny, int _Nz);
  int Ncells;
  int *atoms_inside_cell;
  vector<int> *atoms_ids;
  int *neighbors1_cells; 
  vector<int> *neighbors1_cells_ids;
  int *neighbors2_cells;
  vector<int> *neighbors2_cells_ids;

  void calculateIndex(double [3], int &index);
};
#pragma omp end declare target

#endif 
