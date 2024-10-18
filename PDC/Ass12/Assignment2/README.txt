PDC - PROJECT

i210640     Muneel Haider
i210643     Muhammad Abdullah
i212481     Abdullah Zahoor

README.txt file for configuration and running the project.

1. Save the source code file and the dataset file in the same directory.
2. Make sure you MPI Configured on your master and slave machines.
3. If you are using Visual Studio, then make sure you have MPI_SDK configured for the project.

( FOR MASTER - SLAVE MACHINES ON UBUNTU )
1. Mount master drive on slave.
2. Open masters terminal and type:

    su - mpi

3. Enter your password.
4. Enter: nano i210640_i212481_i210643_G_Project.c
5. Press enter and verify if this is the source code.
6. Press Ctrl + X to exit.
7. Enter: mpicc i210640_i212481_i210643_G_Project.c -o a.out
8. After confirming that it has compiled, enter: mpiexec -n 4 a.out

   Here: n = number of processes you want it to run for.



( FOR VISUAL STUDIO USERS )
1. Open project on visual studio and configure it for MPI and OPENMP.
2. Afer configuration, just press the debugger and run your program.