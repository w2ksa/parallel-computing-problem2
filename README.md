
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

