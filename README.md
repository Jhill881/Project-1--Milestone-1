Campus Resource Reservation System — Milestone 1
How to build and run on the CELL machines
Copy all files (.cpp, .h, Makefile, resources.txt) into one directory on CELL.
Build:
  make
Run (must be run from the same directory as resources.txt):
  ./reservation_system
To rebuild from scratch:
  make clean
   
Program structure
File
Purpose
resource.h / resource.cpp
ResourceManager — loads resources from resources.txt, stores them, displays all resources and their availability.
reservation.h / reservation.cpp
ReservationList — a custom singly linked list storing active reservations (insert, remove, traverse, display).
waitingqueue.h / waitingqueue.cpp
WaitingQueue — a custom linked-list-based FIFO queue for students waiting on a fully booked resource.
cancellationstack.h / cancellationstack.cpp
CancellationStack — a custom linked-list-based LIFO stack recording cancellations so the most recent one can be undone.
main.cpp
Menu-driven program that ties everything together and validates reservation requests.
resources.txt
Sample resource data (id,name,totalUnits), edit or replace with your own.

The waiting list and cancellation stack are implemented from scratch with linked nodes (not std::queue / std::stack) to satisfy the "must be used" requirement for those ADTs.
A design note on collaboration between the data structures
When a reservation is cancelled, the freed unit is automatically offered to the next student in the waiting queue (if any) via cancelReservation() in main.cpp. When a cancellation is undone, the program checks that the resource actually has an available unit before restoring it — if someone else has since taken that slot, the restore is correctly rejected. This was verified by test-running the program end-to-end (see complexity section below for the underlying operations).
Complexity Analysis
Operation
Data structure
Complexity
Explanation
Reservation insertion
Linked list (insertReservation)
O(1)
A new node is always inserted at the head of the list; no traversal is required.
Reservation removal
Linked list (removeReservation)
O(n)
The list must be traversed from the head until the node with the matching reservation ID is found (worst case, it is the last node, or absent).
Waiting-list processing
Queue (addToWaitingList/ removeFromWaitingList)
O(1) each
The queue keeps direct front and rear pointers, so enqueueing at the rear and dequeueing at the front never require traversal.
Undo cancellation
Stack (push / pop)
O(1) each
The stack keeps a direct top pointer, so pushing a new cancellation and popping the most recent one are both constant-time.

Supporting (non-required) operations, for completeness:
Display all resources / availability: O(n) — must print every resource.
Display active reservations / waiting list / cancellation history: O(n) — must traverse and print every node.
Find/validate a resource by ID: O(n) — linear search through the resource vector.
