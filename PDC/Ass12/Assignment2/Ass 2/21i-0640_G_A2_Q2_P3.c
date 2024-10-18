//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//    Muneel Haider
//    i21-0640
//    PDC - Assingment 2
//    Question 2 - Part 3
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
//void AllToAll(const int* sendbuf, int sendcount, MPI_Datatype sendtype, int* recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm) {
//    
//    int size, rank;
//    
//    MPI_Comm_size(comm, &size);
//    MPI_Comm_rank(comm, &rank);
//
//    memset(recvbuf, 0, recvcount * size * sizeof(int));
//
//    for (int i = 0; i < size; i++) {
//    
//        MPI_Sendrecv(sendbuf + i * sendcount, sendcount, sendtype, i, 0, recvbuf + i * recvcount, recvcount, recvtype, i, 0, comm, MPI_STATUS_IGNORE);
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
//    int* sendbuf = (int*)malloc(9 * sizeof(int));
//    int* recvbuf = (int*)malloc(9 * sizeof(int));
//
//    if (sendbuf == NULL || recvbuf == NULL) {
//
//        fprintf(stderr, "Memory allocation failed\n");
//
//        MPI_Abort(MPI_COMM_WORLD, EXIT_FAILURE);
//    }
//
//    for (int i = 0; i < 9; ++i) {
//
//        sendbuf[i] = rank * 10;
//    }
//
//    memset(recvbuf, 0, 8 * sizeof(int));
//
//    AllToAll(sendbuf, 1, MPI_INT, recvbuf, 1, MPI_INT, MPI_COMM_WORLD);
//
//    orderedPrint(rank, size, MPI_COMM_WORLD, recvbuf, 8);
//
//    free(sendbuf);
//    free(recvbuf);
//
//    MPI_Finalize();
//    return 0;
//}