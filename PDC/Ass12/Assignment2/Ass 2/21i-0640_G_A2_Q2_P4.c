//#include <mpi.h>
//#include <stdio.h>
//#include <stdlib.h>
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
//void AllToAll_V(const int* sendbuf, const int* sendcounts, const int* sdispls, MPI_Datatype sendtype, int* recvbuf, const int* recvcounts, const int* rdispls, MPI_Datatype recvtype, MPI_Comm comm) {
//    
//    int size, rank;
//    
//    MPI_Comm_size(comm, &size);
//    MPI_Comm_rank(comm, &rank);
//
//    for (int i = 0; i < size; i++) {
//    
//        MPI_Sendrecv(sendbuf + sdispls[i], sendcounts[i], sendtype, i, 0, recvbuf + rdispls[i], recvcounts[i], recvtype, i, 0, comm, MPI_STATUS_IGNORE);
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
//    int* sendcounts = (int*)malloc(size * sizeof(int));
//    int* sdispls = (int*)malloc(size * sizeof(int));
//    int* recvcounts = (int*)malloc(size * sizeof(int));
//    int* rdispls = (int*)malloc(size * sizeof(int));
//
//    int totalSend = 0, totalRecv = 0;
//
//    for (int i = 0; i < size; ++i) {
//
//        sendcounts[i] = rank + 1; 
//        recvcounts[i] = i + 1;    
//        sdispls[i] = totalSend;
//        rdispls[i] = totalRecv;
//        totalSend += sendcounts[i];
//        totalRecv += recvcounts[i];
//    }
//
//    int* sendbuf = (int*)malloc(totalSend * sizeof(int));
// 
//    for (int i = 0; i < totalSend; ++i) {
//    
//        sendbuf[i] = rank * 100; 
//    }
//    
//    int* recvbuf = (int*)malloc(totalRecv * sizeof(int));
//
//    AllToAll_V(sendbuf, sendcounts, sdispls, MPI_INT, recvbuf, recvcounts, rdispls, MPI_INT, MPI_COMM_WORLD);
//
//    printf("");
//    orderedPrint(rank, size, MPI_COMM_WORLD, recvbuf, totalRecv);
//
//    free(sendcounts);
//    free(sdispls);
//    free(recvcounts);
//    free(rdispls);
//    free(sendbuf);
//    free(recvbuf);
//
//    MPI_Finalize();
//    return 0;
//}
