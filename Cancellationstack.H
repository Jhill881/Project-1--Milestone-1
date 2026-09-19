#ifndef CANCELLATIONSTACK_H
#define CANCELLATIONSTACK_H

#include <string>

// A node in the cancellation history stack.
struct CancelledNode {
    int reservationId;
    int resourceId;
    std::string studentName;
    std::string date;
    CancelledNode* next;
};

// Custom linked-list based LIFO stack used to record cancelled
// reservations so the most recent one can be undone/restored.
class CancellationStack {
private:
    CancelledNode* top;
public:
    CancellationStack();
    ~CancellationStack();

    // Pushes a cancelled reservation onto the stack. O(1)
    void push(int reservationId, int resourceId, const std::string& studentName>

    // Pops the most recently cancelled reservation off the stack. O(1)
    bool pop(CancelledNode& poppedOut);

    // Traverses and prints the cancellation history, most recent first. O(n)
    void display() const;

    bool isEmpty() const;
};
