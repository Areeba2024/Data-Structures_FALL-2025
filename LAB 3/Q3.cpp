#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    string name;
    Passenger* next;

    Passenger(string n) {
        name = n;
        next = NULL;
    }
};

class ReservationSystem {
private:
    Passenger* head;

public:
    ReservationSystem() {
        head = NULL;
    }

    void reserve(string name) {
        Passenger* newPassenger = new Passenger(name);
        if (head == NULL || name < head->name) {
            newPassenger->next = head;
            head = newPassenger;
            cout << name << " has been reserved a ticket.\n";
            return;
        }

        Passenger* curr = head;
        while (curr->next != NULL && curr->next->name < name) {
            curr = curr->next;
        }

        if (curr->name == name || (curr->next && curr->next->name == name)) {
            cout << "Reservation already exists for " << name << ".\n";
            delete newPassenger;
            return;
        }

        newPassenger->next = curr->next;
        curr->next = newPassenger;
        cout << name << " has been reserved a ticket.\n";
    }

    void cancel(string name) {
        if (head == NULL) {
            cout << "No reservations to cancel.\n";
            return;
        }

        if (head->name == name) {
            Passenger* temp = head;
            head = head->next;
            delete temp;
            cout << name << "'s reservation has been canceled.\n";
            return;
        }

        Passenger* curr = head;
        while (curr->next != NULL && curr->next->name != name) {
            curr = curr->next;
        }

        if (curr->next == NULL) {
            cout << "No reservation found for " << name << ".\n";
        } else {
            Passenger* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << name << "'s reservation has been canceled.\n";
        }
    }

    void check(string name) {
        Passenger* curr = head;
        while (curr != NULL) {
            if (curr->name == name) {
                cout << name << " has a reservation.\n";
                return;
            }
            curr = curr->next;
        }
        cout << name << " does not have a reservation.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "No passengers reserved yet.\n";
            return;
        }

        cout << "List of passengers:\n";
        Passenger* curr = head;
        while (curr != NULL) {
            cout << curr->name << endl;
            curr = curr->next;
        }
    }

    ~ReservationSystem() {
        Passenger* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ReservationSystem system;
    int choice;
    string name;

    do {
        cout << "\n1. Reserve Ticket\n";
        cout << "2. Cancel Reservation\n";
        cout << "3. Check Reservation\n";
        cout << "4. Display Passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                system.reserve(name);
                break;
            case 2:
                cout << "Enter name: ";
                cin >> name;
                system.cancel(name);
                break;
            case 3:
                cout << "Enter name: ";
                cin >> name;
                system.check(name);
                break;
            case 4:
                system.display();
                break;
            case 5:
                cout << "Exit.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
