#include <iostream>
#include <string>
using namespace std;

// ===================== Station Node (Doubly Linked List) =====================
struct Station {
    string name;
    Station* prev;
    Station* next;

    Station(string n) : name(n), prev(nullptr), next(nullptr) {}
};

// ===================== Route Planner =====================
class TrainRoutePlanner {
private:
    Station* head;   // Start of route
    Station* tail;   // End of route
    Station* current; // Current station

public:
    TrainRoutePlanner() {
        head = tail = current = nullptr;
    }

    // Add station at end
    void addStation(string name) {
        Station* newStation = new Station(name);
        if (!head) {
            head = tail = current = newStation;
        } else {
            tail->next = newStation;
            newStation->prev = tail;
            tail = newStation;
        }
    }

    // Move forward
    void moveForward() {
        if (current && current->next) {
            current = current->next;
            cout << "Moved forward to: " << current->name << endl;
        } else {
            cout << "End of route reached!" << endl;
        }
    }

    // Move backward
    void moveBackward() {
        if (current && current->prev) {
            current = current->prev;
            cout << "Moved backward to: " << current->name << endl;
        } else {
            cout << "Start of route reached!" << endl;
        }
    }

    // Display full route
    void displayRoute() {
        cout << "Train Route: ";
        Station* temp = head;
        while (temp) {
            if (temp == current)
                cout << "[" << temp->name << "] ";
            else
                cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ===================== Circular Route =====================
struct CircularStation {
    string name;
    CircularStation* next;

    CircularStation(string n) : name(n), next(nullptr) {}
};

class CircularRoute {
private:
    CircularStation* head;
    CircularStation* current;

public:
    CircularRoute() {
        head = current = nullptr;
    }

    void addStation(string name) {
        CircularStation* newStation = new CircularStation(name);
        if (!head) {
            head = newStation;
            head->next = head; // Circular link
            current = head;
        } else {
            CircularStation* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newStation;
            newStation->next = head;
        }
    }

    void moveNext() {
        if (current) {
            current = current->next;
            cout << "Moved to station: " << current->name << endl;
        }
    }

    void displayRoute(int rounds = 1) {
        if (!head) return;
        CircularStation* temp = head;
        cout << "Circular Route: ";
        for (int r = 0; r < rounds; r++) {
            do {
                if (temp == current)
                    cout << "[" << temp->name << "] ";
                else
                    cout << temp->name << " ";
                temp = temp->next;
            } while (temp != head);
        }
        cout << endl;
    }
};

// ===================== Main Program =====================
int main() {
    cout << "===== Virtual Train Route Planner =====\n";

    // Doubly Linked List Route
    TrainRoutePlanner planner;
    planner.addStation("Station A");
    planner.addStation("Station B");
    planner.addStation("Station C");
    planner.addStation("Station D");

    planner.displayRoute();
    planner.moveForward();
    planner.moveForward();
    planner.displayRoute();
    planner.moveBackward();
    planner.displayRoute();

    cout << "\n===== Circular Train Route (Metro Loop) =====\n";
    CircularRoute loop;
    loop.addStation("Loop 1");
    loop.addStation("Loop 2");
    loop.addStation("Loop 3");
    loop.addStation("Loop 4");

    loop.displayRoute(2); // Show 2 loops
    loop.moveNext();
    loop.displayRoute();

    return 0;
}
