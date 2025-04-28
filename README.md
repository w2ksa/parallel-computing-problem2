# Parallel Computing - Problem 2

## Message Passing Interface (MPI) - Ring Communication

### Project Overview
This project implements a **Message Passing Interface (MPI)** program in **C language** that simulates a **ring communication** pattern among multiple processes.  
Each process sends a message to its successor and receives a message from its predecessor in the ring.

The goal is to demonstrate basic message-passing and communication patterns in a distributed system.

---

### Objectives
- Implement a distributed message passing ring.
- Each process sends a message to the next process.
- Each process receives a message from the previous process.
- After receiving, each process prints the received message.

---

### Implementation Details
- Language: **C**
- Library: **MPI** (Message Passing Interface)
- Communication pattern: **Ring Topology**
- Process 0 starts the message, and it circulates through the ring.
- Each process updates the message before sending it to the next process.

---

### How It Works
1. Each process is assigned a unique rank by MPI.
2. Process 0 creates an initial message and sends it to Process 1.
3. Each process receives a message from its predecessor.
4. After receiving, the process:
   - Prints the received message.
   - Appends its own process rank to the message.
   - Sends the updated message to its successor.
5. Finally, Process 0 receives the message back and prints the full message.

---

### Project Structure
- `problem2_message_passing_ring.c`: The C source code implementing the solution.

---

### Output
The output will show each process printing the received message.

Example output when running with 3 processes:

Process 1 received message: 'Hello from Process 0' Process 2 received message: 'Hello from Process 0 -> P1' Process 0 received message: 'Hello from Process 0 -> P1 -> P2'



---

### How to Compile and Run

**To compile the code:**
```bash
mpicc -o ring_mpi problem2_message_passing_ring.c
To run the program with 3 processes:
 mpirun -np 3 ./ring_mpi
Explanation:

-np 3 specifies running with 3 processes.

./ring_mpi is the compiled executable.

Notes
Make sure you have MPI installed (e.g., OpenMPI or MPICH).

You can change the number of processes by modifying the -np value.

The program demonstrates distributed message passing using a ring topology


