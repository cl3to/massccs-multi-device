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

#include "headers/LCL.h"

LCL::LCL(int _Ncells, int *_n1_cells, int *_n2_cells, int *_atoms_cell, int *_n1_cells_ids, int *_n2_cells_ids, int *_ids, 
         double _lj_cutoff, double _skin, double _lx, double _ly, double _lz, int _Nx, int _Ny, int _Nz) :
         Ncells(_Ncells), n1_cells(_n1_cells), n2_cells(_n2_cells), atoms_cell(_atoms_cell), n1_cells_ids(_n1_cells_ids), 
         n2_cells_ids(_n2_cells_ids), ids(_ids), lj_cutoff(_lj_cutoff), skin(_skin), lx(_lx), ly(_ly), lz(_lz), Nx(_Nx), Ny(_Ny), Nz(_Nz)
{

  corner[0] = -lx;
  corner[1] = -ly;
  corner[2] = -lz;
  
  calculateNeighborsVectors();
}

void LCL::calculateNeighborsVectors() {

  // initialize the LCL
  atoms_inside_cell = new int [Ncells]();
  atoms_ids = new vector<int> [Ncells]; 
  neighbors1_cells = new int[Ncells]();
  neighbors1_cells_ids = new vector<int> [Ncells];
  neighbors2_cells = new int[Ncells]();
  neighbors2_cells_ids = new vector<int> [Ncells];
  
  for (int i = 0; i < Ncells; i++) {
    atoms_inside_cell[i] = atoms_cell[i];
    neighbors1_cells[i] = n1_cells[i];
    neighbors2_cells[i] = n2_cells[i]; 
    atoms_ids[i].push_back(0);
    atoms_ids[i].clear();
    neighbors1_cells_ids[i].push_back(0);
    neighbors1_cells_ids[i].clear();
    neighbors2_cells_ids[i].push_back(0);
    neighbors2_cells_ids[i].clear();
  }
 
  int id1 = 0;
  int id2 = 0;
  int id3 = 0;
  for (int i = 0; i < Ncells; i++) {
    for (int j = 0; j < neighbors1_cells[i]; j++) {      
      neighbors1_cells_ids[i].emplace_back(n1_cells_ids[id1]);
      id1 += 1;
    }

    for (int j = 0; j < neighbors2_cells[i]; j++) {
      neighbors2_cells_ids[i].emplace_back(n2_cells_ids[id2]);
      id2 += 1;
    }

    for (int j = 0; j < atoms_inside_cell[i]; j++) {
      atoms_ids[i].emplace_back(ids[id3]);
      id3 += 1;
    }
  } 
  
}

// calculate the cell index for specify position
void LCL::calculateIndex(double pos[3], int &index) {
double xi, yi, zi;
int i, j, k;

xi = pos[0] - corner[0];
i = (int)floor(xi/(lj_cutoff + skin));
yi = pos[1] - corner[1];
j = (int)floor(yi/(lj_cutoff + skin));
zi = pos[2] - corner[2];
k = (int)floor(zi/(lj_cutoff + skin));

index = k + Nz*j + Nz*Ny*i;
}

void LCL::print() {
/*int filled_cells, empty_cells, average_atoms_cells, maximum_atoms_cells, minimum_atoms_cells;

average_atoms_cells = 0;
maximum_atoms_cells = 0;
minimum_atoms_cells = 10000000; //moleculeTarget->natoms;
empty_cells = 0;
filled_cells = 0;
for (int i = 0; i < Ncells; i++) {
   if (atoms_inside_cell[i] == 0) {
     empty_cells += 1;
   } else {
     average_atoms_cells += atoms_inside_cell[i];
     filled_cells += 1;
     if (atoms_inside_cell[i] > maximum_atoms_cells) {
       maximum_atoms_cells = atoms_inside_cell[i];
     }
     if (atoms_inside_cell[i] < minimum_atoms_cells) {
       minimum_atoms_cells = atoms_inside_cell[i];
     }
   }
}

cout << "*********************************************************"
            << endl;
cout << "Linked-cell: " << endl;
cout << "Numbers of cells: " << Ncells << endl;
cout << "Nx: " << Nx << " Ny: " << Ny << " Nz: " << Nz << endl;
cout << "Filled cells: " << filled_cells << endl;
cout << "Empty cells: " << empty_cells << endl;
cout << "Average atoms per cell: " << ((float)average_atoms_cells)/((float)filled_cells) << endl;
cout << "Maximum atoms per cell: " << maximum_atoms_cells << endl;
cout << "Minimum atoms per cell: " << minimum_atoms_cells << endl;
cout << "Simulation box: " << endl;
cout << "lx: " << lx << " Ang" << endl;
cout << "ly: " << ly << " Ang" << endl;
cout << "lz: " << lz << " Ang" << endl;
*/
}
