//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//    Muneel Haider
//    i21-0640
//    PDC - Assingment 2
//    Question 2 - Part 2
//*/
//
//void orderedPrint(int rank, int size, MPI_Comm comm, int* array, int array_size) {
//    
//    int token;
//    
//    if (rank == 0) {
//    
//        printf("Process %d received: ", rank);
//        
//        for (int i = 0; i < array_size; ++i) {
//        
//            printf("%d ", array[i]);
//        }
//        
//        printf("\n");
//        fflush(stdout);
//        
//        if (size > 1) {
//
//            MPI_Send(&token, 0, MPI_INT, 1, 0, comm);
//        }
//    }
//    else {
//
//        MPI_Recv(&token, 0, MPI_INT, rank - 1, 0, comm, MPI_STATUS_IGNORE);
//
//        printf("Process %d received: ", rank);
//
//        for (int i = 0; i < array_size; ++i) {
//
//            printf("%d ", array[i]);
//        }
//
//        printf("\n");
//        fflush(stdout);
//
//        if (rank < size - 1) {
//            
//            MPI_Send(&token, 0, MPI_INT, rank + 1, 0, comm);
//        }
//    }
//}
//
//
//void allGather_V(const int* sendbuf, int sendcount, MPI_Datatype sendtype, int* recvbuf, const int* recvcounts, const int* displs, MPI_Datatype recvtype, MPI_Comm comm) {
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
//            memcpy(recvbuf + displs[rank], sendbuf, sendcount * sizeof(int));
//        }
//        else {
//            
//            MPI_Send(sendbuf, sendcount, sendtype, i, 0, comm);
//            MPI_Recv(recvbuf + displs[i], recvcounts[i], recvtype, i, 0, comm, MPI_STATUS_IGNORE);
//        }
//    }
//}
//
//int main() {
//
//    MPI_Init(NULL, NULL);
//
//    int rank, size;
//
//    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//    MPI_Comm_size(MPI_COMM_WORLD, &size);
//
//    int sendbuf[8];
//    int sendcount = rank + 1;
//
//    for (int i = 0; i < sendcount; ++i) {
//    
//        sendbuf[i] = (rank + 1) * 10;
//    }
//
//    int* recvcounts = (int*)malloc(size * sizeof(int));
//    int* displs = (int*)malloc(size * sizeof(int));
//
//    int totalcount = 0;
//
//    for (int i = 0; i < size; ++i) {
//
//        recvcounts[i] = i + 1;
//        displs[i] = totalcount;
//        totalcount += recvcounts[i];
//    }
//
//    int* recvbuf = (int*)malloc(totalcount * sizeof(int));
//
//    allGather_V(sendbuf, sendcount, MPI_INT, recvbuf, recvcounts, displs, MPI_INT, MPI_COMM_WORLD);
//
//    orderedPrint(rank, size, MPI_COMM_WORLD, recvbuf, totalcount);
//
//    free(recvcounts);
//    free(displs);
//    free(recvbuf);
//
//    MPI_Finalize();
//}
