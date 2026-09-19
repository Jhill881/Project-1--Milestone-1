include "waitingqueue.h"
#include <iostream>

WaitingQueue::WaitingQueue() : front(nullptr), rear(nullptr) {}

WaitingQueue::~WaitingQueue() {
    WaitingNode* current = front;
    while (current != nullptr) {
        WaitingNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void WaitingQueue::addToWaitingList(const std::string& studentName, int resourc>
    WaitingNode* newNode = new WaitingNode();
    newNode->studentName = studentName;
    newNode->resourceId = resourceId;
    newNode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

bool WaitingQueue::removeFromWaitingList(WaitingNode& removedOut) {
    if (front == nullptr) return false;

    WaitingNode* temp = front;
    removedOut = *temp;

    front = front->next;

