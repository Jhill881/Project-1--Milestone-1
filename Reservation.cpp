#include "reservation.h"
#include <iostream>

ReservationList::ReservationList() : head(nullptr), nextId(1) {}

ReservationList::~ReservationList() {
    ReservationNode* current = head;
    while (current != nullptr) {
        ReservationNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

int ReservationList::insertReservation(int resourceId, const std::string& stude>
    ReservationNode* newNode = new ReservationNode();
    newNode->reservationId = nextId++;
    newNode->resourceId = resourceId;
    newNode->studentName = studentName;
    newNode->date = date;
    newNode->next = head;
    head = newNode;
    return newNode->reservationId;
}

bool ReservationList::removeReservation(int reservationId, ReservationNode& rem>
    ReservationNode* current = head;
    ReservationNode* previous = nullptr;

    while (current != nullptr) {
        if (current->reservationId == reservationId) {
            removedOut = *current;

            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

ReservationNode* ReservationList::find(int reservationId) {
    ReservationNode* current = head;
    while (current != nullptr) {
        if (current->reservationId == reservationId) return current;
        current = current->next;
}
    return nullptr;
}

void ReservationList::displayAll() const {
    std::cout << "\n--- Active Reservations ---\n";
    if (head == nullptr) {
        std::cout << "No active reservations.\n";
        return;
    }

    std::cout << "ResID\tResourceID\tStudent\t\tDate\n";
    ReservationNode* current = head;
    while (current != nullptr) {
        std::cout << current->reservationId << "\t" << current->resourceId << ">
                  << current->studentName << "\t\t" << current->date << "\n";
        current = current->next;
    }
}

bool ReservationList::isEmpty() const {
    return head == nullptr;
}
 


