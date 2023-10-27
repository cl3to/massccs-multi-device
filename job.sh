#!/bin/bash
#SBATCH --nodes=3                      #Numero de Nós
#SBATCH --ntasks-per-node=1            #Numero de tarefas por Nó
#SBATCH --ntasks=3                     #Numero total de tarefas MPI
#SBATCH --cpus-per-task=24             #Numero de threads
#SBATCH -p sequana_cpu_dev             #Fila (partition) a ser utilizada
#SBATCH -J ompc                         #Nome job
#SBATCH --exclusive                    #Utilização exclusiva dos nós durante a execução do job
#SBATCH --time 00:20:00

#Exibe os nós alocados para o Job
echo $SLURM_JOB_NODELIST
nodeset -e $SLURM_JOB_NODELIST

cd $SLURM_SUBMIT_DIR
module load mpich/4.0.2
module load ucx/1.12

#configura o numero de threads, de acordo com o parametro definido no Slurm
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
export OMPCLUSTER_SCHEDULER=roundrobin
export OMPCLUSTER_BLOCKING_SCHEDULER=1

echo $SLURM_NTASKS
echo $SLURM_CPUS_PER_TASK

srun --mpi=pmi2 -n $SLURM_NTASKS -c $SLURM_CPUS_PER_TASK singularity exec runtime_latest.sif ./build/bin/massccs input_Nitrogen.json > out

