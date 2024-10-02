#!/bin/bash
#PBS -l walltime=00:01:00,nodes=1:ppn=3
#PBS -N my_job
#PBS -q batch
cd $PBS_O_WORKDIR
export OMP_NUM_THREADS=$PBS_NUM_PPN
export OMP_NESTED=TRUE
./parallel_mp

