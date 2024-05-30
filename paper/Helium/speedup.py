#!/usr/bin/env python
#
import sys,os,string,math
import csv
from numpy import *

if len(sys.argv) != 3:
   print('Not found file list of proteins' %sys.argv[0])
   sys.exit(1)

filelist = str(sys.argv[1])
gas = str(sys.argv[2])
#ntask = str(sys.argv[3])
ntask = [2,4,8,16]
outfiles = open(filelist, 'r')
outlines = outfiles.readlines()

word1 = 'Total time:'
speedup = zeros(len(ntask))
time = zeros(len(ntask))

for outname in outlines:
   # name of xyz file
   xyzfile = outname.strip() #split(".")[0]
   tmpfile = "../"+xyzfile
   # number of atoms
   xyzname = open(tmpfile,'r')
   xyzline = xyzname.readline()
   natoms = xyzline.strip()
   xyzname.close()

   name = xyzfile.split(".")[0]
   # He_CCS_ntask1_01_1hrc_carga_6_min.log
   # single node 
   #logname = gas+"_CCS_ntask"+str(ntask[0])+"_"+name+".log"
   #logfile = open(logname, 'r')
   #loglines = logfile.readlines()

   # 1 node
   #serial = 0.0
   #pp = 0
   #for line in loglines:
   #   if line.find(word1) != -1:
        #print("%s" % line.split()[2])
   #     serial += float(line.split()[2])
   #     pp += 1
   #logfile.close()
   #if pp == 0: print("%s",logname)
   #serial /= pp
   #time[0] = serial/60.0
   # He_CCS_ntask16_01_1hrc_carga_6_min.log
   # inter nodes
   for i in range(len(ntask)):
      logname = gas+"_CCS_nodes"+str(ntask[i])+"_"+name+".log"
      logfile = open(logname, 'r')
      loglines = logfile.readlines()

      parallel = 0.0
      pp = 0
      for line in loglines:
         if line.find(word1) != -1:
           #print("%s" % line.split()[2])
           parallel += float(line.split()[2])
           pp += 1
      logfile.close()
      if pp == 0: print("%s",logname)
      parallel /= pp
      time[i] = parallel/60.0
      #speedup[i] = serial/parallel

   print("%s %f %f %f %f" % (natoms,time[0],time[1],time[2],time[3]))
   #print("%s %f %f %f %f %f %f" % (natoms,speedup[0],speedup[1],speedup[2],speedup[3],speedup[4],speedup[5]))
