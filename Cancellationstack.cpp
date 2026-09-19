#include "cancellationstack.h"
#include <iostream>

CancellationStack::CancellationStack() : top(nullptr) {}

CancellationStack::~CancellationStack() {
    CancelledNode* current = top;
    while (current != nullptr) {
        CancelledNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void CancellationStack::push(int reservationId, int resourceId, const std::stri>
    CancelledNode* newNode = new CancelledNode();
    newNode->reservationId = reservationId;
    newNode->resourceId = resourceId;
    newNode->studentName = studentName;
    newNode->date = date;
newNode->next = top;
    top = newNode;
}

bool CancellationStack::pop(CancelledNode& poppedOut) {
    if (top == nullptr) return false;

    CancelledNode* temp = top;
    poppedOut = *temp;

    top = top->next;
    delete temp;
    return true;
}

void CancellationStack::display() const {
    std::cout << "\n--- Cancellation History (most recent first) ---\n";
    if (top == nullptr) {
        std::cout << "No cancelled reservations.\n";
        return;
    }

    std::cout << "ResID\tResourceID\tStudent\t\tDate\n";
    CancelledNode* current = top;
    while (current != nullptr) {
        std::cout << current->reservationId << "\t" << current->resourceId << ">
                  << current->studentName << "\t\t" << current->date << "\n";
        current = current->next;
    }
}

bool CancellationStack::isEmpty() const {
    return top == nullptr;
}

