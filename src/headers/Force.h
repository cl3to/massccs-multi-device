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

#ifndef MASSCCS_V1_FORCE_H
#define MASSCCS_V1_FORCE_H

#include "Mol.h"
#include "GasProbe.h"
#include <cmath>
#include <vector>
#include "LCL.h"
#include "Constants.h"
#include "omp.h"

#pragma omp declare target
class Force {
private:
  double lj_cutoff;
  double alpha;
  double coul_cutoff;
  LCL *linkedcell;
  int Nx, Ny, Nz;
  Mol *moleculeTarget;
  
public:
 
  Force(Mol *_moleculeTarget, LCL *_linkedcell, double _lj_cutoff, double _alpha, double _coul_cutoff); 

  void lennardjones(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_LC(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb_LC(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void coulomb(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void coulomb_LC(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_induced_dipole(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_induced_dipole_LC(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void coulomb_induced_dipole(GasProbe *gas, int iatom, vector<double> n, vector<double> &f, double &Up);
  void coulomb_induced_dipole_LC(GasProbe *gas, int iatom, vector<double> n, vector<double> &f, double &Up);
  void coulomb_induced_dipole_iso(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void coulomb_induced_dipole_iso_LC(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void nitrogen2_LC(GasProbe *gas, vector<double> &f, double &Up);
  void nitrogen(GasProbe *gas, vector<double> &f, double &Up);
  // CO2 
  void lennardjones_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_LC_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb_LC_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb_induced_dipole_iso_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);
  void lennardjones_coulomb_induced_dipole_iso_LC_CO2(GasProbe *gas, int iatom, vector<double> &f, double &Up);

  //double Switch(double rIn, double rOut, double r);
  //double DSwitch(double rIn, double rOut, double r);
};
#pragma omp end declare target
#endif 
