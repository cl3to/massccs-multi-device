#!/bin/bash
#SBATCH --nodes=9                      # numbers of nodes
#SBATCH --ntasks-per-node=1            # numbers of taks per node
#SBATCH --ntasks=9                      
#SBATCH --cpus-per-task=24             # numbers of threads per node

cd $SLURM_SUBMIT_DIR

module purge
module load mpich/4.0.2
module load ucx/1.12

#configure the numbers of threads
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
export LIBOMP_NUM_HIDDEN_HELPER_THREADS=24
export OMPCLUSTER_SCHEDULER=roundrobin
export OMPCLUSTER_BLOCKING_SCHEDULER=1

pqr_list=$1  # "sort_list.dat"
input=$2  # "input.json"
gas=$3  # choice beteween "He" or "N2"

# number of pqrs files 
npqr=`wc -l $pqr_list | awk '{print $1}'`
samples=10

let nworkers=$SLURM_NTASKS-1

for((i=0;i<$npqr;i++)); do

let j=$i+1
nfile=$j'p'

pqr_file=`sed -n $nfile $pqr_list`
pqr_name=`echo ${pqr_file%.*}`
log_file=$pqr_name'.log'

cat > $input <<!
{
  "targetFileName": "$pqr_file",
  "ntask" : $nworkers,
  "numberProbe" : 10000,
  "nIter" : 10,
  "seed" : 2104,
  "dt" : 10.0,
  "Temp" : 298.0,
  "skin" : 0.01,
  "GasBuffer" : "$gas",
  "Equipotential" : "no",
  "Short-range cutoff" : "yes",
  "LJ-cutoff" : 12.0,
  "Long-range forces" : "yes",
  "Long-range cutoff" : "yes",
  "Coul-cutoff" : 25.0,
  "polarizability" : "yes"
}
!

for((k=0;k<$samples;k++)); do
  srun --mpi=pmi2 -n $SLURM_NTASKS -c $SLURM_CPUS_PER_TASK singularity exec runtime_latest.sif ./build/bin/massccs $input >> $gas'_CCS_nodes'$nworkers'_'$log_file
done

done
