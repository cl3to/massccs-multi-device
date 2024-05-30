# MassCSS-OMPC data set

This directory contains:

* The files for all proteins considered in this work are founded in the following ["link"](https://drive.google.com/file/d/1NYWqjpee3eDW_63tvzY9bVBhLHLGi3jX/view?usp=share_link) (in extended XYZ-format), for more information see the table S2 of supplementary material of our published paper ["S. Cajahuaringa, D. L. Z. Caetano, L. N. Zanotto, G. Araujo and M. S. Skaf, MassCCS: A high performance collision cross-section software for large macromolecular assemblies, J. Chem. Inf. Model. 2023, 63, 11, 3557–3566"](https://doi.org/10.1021/acs.jcim.3c00405)

* job_ompc.sh slurm job script to perform calculation to specify nodes, in this case for 9 nodes, one head node and 8 workers nodes, execute using the following command
```bash
sbatch job_ompc.sh sorlist.dat input.json He
```

* job_ompc_tasks slurm job script to perform calculation with more tasks that workers nodes, in this case for 9 nodes, one head node and 8 workers nodes, execute using the following command
```bash
sbatch job_ompc_tasks.sh sorlist.dat input.json He
```

* The outputs directory contains the ouput files for the CCS calculation for Helium and Nitorgen buffer gases, run in a 2, 4, 8 and 16, workers nodes.

## The repository contents:

[`Helium`](Helium): This directory contains output for CCS calculations using Helium buffer gas.

[`Nitrogen`](Nitorgen): This directory contains output for CCS calculations using Nitrogen buffer gas.

[`Helium_tasks`](Helium): This directory contains output for CCS calculations using more tasks than available workers nodes for Helium buffer gas.

[`Nitrogen_tasks`](Nitorgen): This directory contains output for CCS calculations using more tasks than available workers nodes for Nitrogen buffer gas.





