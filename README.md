# Project_ExE

DESCRIPTION:

This Project is a prototype demonstration for helping patients suffering from epilepsy and seizures become more independent by constantly monitoring their heart rates automatically and taking certain actions based on any discrepancy in the heart rates while walking.

The project uses acceleration value of 1.66 m^2/s as a metric to differentiate between walking and running because there could be discrepancies in the heart rates because of running.

There are 2 types of actions that could be taken based on minor and major discrepancy in the heart rates. In case of minor discrepancy in the heart rates- the patients location is sent to a relative and an automatic call is made to that relative, all using messenger. In case of major discrepancy in the heart rates- the patients location is sent to 911 and an automatic call is made to 911.

SETUP:

1) Download CodeBlocks using MINGW installer method. 
2) Download C++ graphics library
3) Add libbgi.a from C++ graphics library to MINGW lib folder of CodeBlocks
4) Add path of libbgi.a in the MINGW folder of CodeBlocks in the linker settings of compiler settings in CodeBlocks
5) Add the following files to linker settings of compiler setting in CodeBlocks: -lbgi, -lgdi32, -lcomdlg32, -luuid, -loleaut32, -lole32
6) Create a Console Application project file in CodeBlocks and add main.cpp file from repo to this project
7) Make sure the batch files and python files from repo are in the same folder as the main.cpp file
8) Next Download python from www.python.org and add python path into the environment variables to your system
9) Import selenium module for python files using command line
10) Build and Run the Code in CodeBlocks and see the results
