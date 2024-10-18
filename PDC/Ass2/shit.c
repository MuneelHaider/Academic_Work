#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void my_MPI_Allgather(int send_data, int *recv_data, int num_procs, int my_rank) {
    // Each process sends its send_data to all other processes
    for (int i = 0; i < num_procs; ++i) {
        if (i == my_rank) {
            // Broadcast its send_data to all other processes
            for (int j = 0; j < num_procs; ++j) {
                if (j != my_rank) {
                    MPI_Send(&send_data, 1, MPI_INT, j, 0, MPI_COMM_WORLD);
                }
            }
            recv_data[my_rank] = send_data; // Copy own data to own slot in recv_data
        } else {
            // Receive data from process i
            MPI_Recv(&recv_data[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
}

void my_MPI_Allgatherv(int send_data, int *recv_data, int *recv_counts, int *displs, int num_procs, int my_rank) {
    // Similar to my_MPI_Allgather, but with varying amounts of data from each process
    for (int i = 0; i < num_procs; ++i) {
        if (i == my_rank) {
            // Broadcast its send_data to all other processes
            for (int j = 0; j < num_procs; ++j) {
                if (j != my_rank) {
                    MPI_Send(&send_data, recv_counts[my_rank], MPI_INT, j, 0, MPI_COMM_WORLD);
                }
            }
            // Copy own data to own slot in recv_data
            for (int k = 0; k < recv_counts[my_rank]; ++k) {
                recv_data[displs[my_rank] + k] = send_data;
            }
        } else {
            // Receive data from process i
            MPI_Recv(&recv_data[displs[i]], recv_counts[i], MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
}

void my_MPI_Alltoall(int *send_data, int *recv_data, int num_procs, int my_rank) {
    // Each process sends a distinct piece of data to every other process
    for (int i = 0; i < num_procs; ++i) {
        if (i == my_rank) {
            // Copy own data to own slot in recv_data
            recv_data[my_rank] = send_data[my_rank];
        } else {
            // Send and receive operations are paired
            MPI_Send(&send_data[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Recv(&recv_data[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
}

void my_MPI_Alltoallv(int *send_data, int *send_counts, int *sdispls, int *recv_data, int *recv_counts, int *rdispls, int num_procs, int my_rank) {
    // Each process sends a different amount of data to every other process
    for (int i = 0; i < num_procs; ++i) {
        if (i == my_rank) {
            // Copy own data to own slot in recv_data
            for (int k = 0; k < send_counts[my_rank]; ++k) {
                recv_data[rdispls[my_rank] + k] = send_data[sdispls[my_rank] + k];
            }
        } else {
            // Send and receive operations are paired
            MPI_Send(&send_data[sdispls[i]], send_counts[i], MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Recv(&recv_data[rdispls[i]], recv_counts[i], MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int num_procs, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // Allgather and Allgatherv setup
    int send_data = my_rank + 100; // Unique send data for each process
    int *allgather_recv_data = malloc(num_procs * sizeof(int));
    int *allgatherv_recv_data = malloc(num_procs * num_procs * sizeof(int));
    int *recv_counts = malloc(num_procs * sizeof(int));
    int *displs = malloc(num_procs * sizeof(int));

    for (int i = 0; i < num_procs; ++i) {
        recv_counts[i] = num_procs;
        displs[i] = i * num_procs;
    }

    // Alltoall and Alltoallv setup
    int *alltoall_send_data = malloc(num_procs * sizeof(int));
    int *alltoall_recv_data = malloc(num_procs * sizeof(int));
    int *alltoallv_send_data = malloc(num_procs * num_procs * sizeof(int));
    int *alltoallv_recv_data = malloc(num_procs * num_procs * sizeof(int));
    int *send_counts = malloc(num_procs * sizeof(int));
    int *sdispls = malloc(num_procs * sizeof(int));
    int *rdispls = malloc(num_procs * sizeof(int));

    for (int i = 0; i < num_procs; ++i) {
        alltoall_send_data[i] = send_data; // Same data sent to all for simplicity
        send_counts[i] = num_procs;
        sdispls[i] = i * num_procs;
        rdispls[i] = i * num_procs;
        for (int j = 0; j < num_procs; ++j) {
            alltoallv_send_data[sdispls[i] + j] = send_data + j; // Different data for each process
        }
    }

    // Call the custom collective functions
    my_MPI_Allgather(send_data, allgather_recv_data, num_procs, my_rank);
    my_MPI_Allgatherv(send_data, allgatherv_recv_data, recv_counts, displs, num_procs, my_rank);
    my_MPI_Alltoall(alltoall_send_data, alltoall_recv_data, num_procs, my_rank);
    my_MPI_Alltoallv(alltoallv_send_data, send_counts, sdispls, alltoallv_recv_data, recv_counts, rdispls, num_procs, my_rank);

    // Output the results for verification
    printf("Rank %d Allgather received: ", my_rank);
    for (int i = 0; i < num_procs; i++) {
        printf("%d ", allgather_recv_data[i]);
    }
    printf("\n");

    printf("Rank %d Allgatherv received: ", my_rank);
    for (int i = 0; i < num_procs * num_procs; i++) {
        printf("%d ", allgatherv_recv_data[i]);
    }
    printf("\n");

    printf("Rank %d Alltoall received: ", my_rank);
    for (int i = 0; i < num_procs; i++) {
        printf("%d ", alltoall_recv_data[i]);
    }
    printf("\n");

    printf("Rank %d Alltoallv received: ", my_rank);
    for (int i = 0; i < num_procs * num_procs; i++) {
        printf("%d ", alltoallv_recv_data[i]);
    }
    printf("\n");

    // Clean up
    free(allgather_recv_data);
    free(allgatherv_recv_data);
    free(recv_counts);
    free(displs);
    free(alltoall_send_data);
    free(alltoall_recv_data);
    free(alltoallv_send_data);
    free(alltoallv_recv_data);
    free(send_counts);
    free(sdispls);
    free(rdispls);

    MPI_Finalize();
    return 0;
}
