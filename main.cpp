#include <iostream>
#include <limits>
#include "resource.h"
#include "reservation.h"
#include "waitingqueue.h"
#include "cancellationstack.h"

using namespace std;

void printMenu() {
    cout << "\n============================================\n";
    cout << " Campus Resource Reservation System\n";
    cout << "============================================\n";
    cout << "1. Display all resources\n";
    cout << "2. Display resource availability\n";
    cout << "3. Create a reservation\n";
    cout << "4. Cancel a reservation\n";
    cout << "5. Display active reservations\n";
    cout << "6. Display waiting list\n";
    cout << "7. Restore most recently cancelled reservation (Undo)\n";cout << "8. Display cancellation history\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int readInt(const string& prompt) {
    if (!prompt.empty()) cout << prompt;
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}
