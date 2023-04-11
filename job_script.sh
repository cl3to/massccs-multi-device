#!/bin/bash

#SBATCH --job-name=ompc
#SBATCH --output=ompc.out
#SBATCH --nodes=3
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=0
#SBATCH --time=72:00:00

module purge
module load mpich/4.0.2-cuda

ulimit -s unlimited

#srun -n 2 singularity exec runtime_latest.sif ./hello-world
export OMP_NUM_THREADS=1
srun -N3  --mpi=pmi2 singularity exec runtime_latest.sif ./build/massccs input.json
