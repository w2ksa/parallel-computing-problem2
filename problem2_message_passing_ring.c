
// Problem 2: Message Passing Interface (MPI) - Ring Communication
#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int world_rank, world_size;
    char message[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int next = (world_rank + 1) % world_size;
    int prev = (world_rank - 1 + world_size) % world_size;

    if (world_rank == 0) {
        // Process 0 starts the message
        strcpy(message, "Hello from Process 0");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, next, 0, MPI_COMM_WORLD);
        MPI_Recv(message, 100, MPI_CHAR, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received message: '%s'\n", world_rank, message);
    } else {
        // Other processes
        MPI_Recv(message, 100, MPI_CHAR, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received message: '%s'\n", world_rank, message);

        strcat(message, " -> ");
        char temp[20];
        sprintf(temp, "P%d", world_rank);
        strcat(message, temp);

        MPI_Send(message, strlen(message) + 1, MPI_CHAR, next, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
