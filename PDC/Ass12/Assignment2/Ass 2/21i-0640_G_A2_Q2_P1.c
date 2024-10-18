//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//    Muneel Haider
//    i21-0640
//    PDC - Assingment 2
//    Question 2 - Part 1
//*/
//
//void allGather(const int* sendbuf, int sendcount, int* recvbuf, int recvcount, MPI_Comm comm) {
//    
//    int size, rank;
//
//    MPI_Comm_size(comm, &size);
//    MPI_Comm_rank(comm, &rank);
//
//    for (int i = 0; i < size; i++) {
//
//        if (i == rank) {
//
//            memcpy(recvbuf + rank * recvcount, sendbuf, sendcount * sizeof(int));
//        }
//        else {
//
//            MPI_Send(sendbuf, sendcount, MPI_INT, i, 0, comm);
//            MPI_Recv(recvbuf + i * recvcount, recvcount, MPI_INT, i, 0, comm, MPI_STATUS_IGNORE);
//        }
//    }
//}
//
//void orderedPrint(int rank, int size, MPI_Comm comm, const char* message) {
//
//    if (rank == 0) {
//
//        printf("%s \n", message);
//
//        MPI_Send(&rank, 1, MPI_INT, 1, 0, comm);
//    }
//    else {
//
//        int prev_rank = rank - 1;
//
//        MPI_Recv(&prev_rank, 1, MPI_INT, prev_rank, 0, comm, MPI_STATUS_IGNORE);
//
//        printf("%s \n", message);
//
//        if (rank < size - 1) {
//
//            MPI_Send(&rank, 1, MPI_INT, rank + 1, 0, comm);
//        }
//    }
//}
//
//int main(int argc, char* argv[]) {
//
//    MPI_Init(&argc, &argv);
//
//    int rank, size;
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    int sendbuf[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
//
//    const int sendcount = sizeof(sendbuf) / sizeof(sendbuf[0]);
//
//    int* recvbuf = (int*)malloc(sendcount * size * sizeof(int));
//
//    allGather(sendbuf, sendcount, recvbuf, sendcount, MPI_COMM_WORLD);
//
//    // SO PRINTING IS SYNCHRONIZED, NOTHING TO DO WITH COMPUTATION
//    MPI_Barrier(MPI_COMM_WORLD);
// 
//    if (rank == 0) {
//    
//        for (int i = 0; i < size; i++) {
//        
//            printf("Process %d received: ", i);
//            
//            for (int j = 0; j < sendcount; j++) {
//            
//                printf("%d ", recvbuf[i * sendcount + j]);
//            }
//
//            printf("\n");
//        }
//    }
//
//    free(recvbuf);
//
//    MPI_Finalize();
//    return 0;
//}