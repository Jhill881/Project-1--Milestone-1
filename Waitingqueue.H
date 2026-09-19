#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <string>

// A node in the waiting list queue.
struct WaitingNode {
    std::string studentName;
    int resourceId;
    WaitingNode* next;
};

// Custom linked-list based FIFO queue used to manage students waiting
// for a resource that is currently fully booked.
class WaitingQueue {
private:
    WaitingNode* front;
    WaitingNode* rear;

public:
  WaitingQueue();
    ~WaitingQueue();

    // Adds a student to the back of the waiting list. O(1)
    void addToWaitingList(const std::string& studentName, int resourceId);

    // Removes and returns the student at the front of the waiting list. O(1)
    bool removeFromWaitingList(WaitingNode& removedOut);

    // Traverses and prints the entire waiting list. O(n)
    void display() const;

    bool isEmpty() const;
};

#endif 

