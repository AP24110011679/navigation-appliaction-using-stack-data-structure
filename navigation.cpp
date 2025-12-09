#include <iostream>
#include <stack>
#include <string>

using namespace std;

void visitNewLocation(stack<string> &backStack, stack<string> &forwardStack, string &currentLocation) {
    string newLocation;
    cout << "Enter new location name: ";
    getline(cin >> ws, newLocation);  // read full line with spaces

    if (!currentLocation.empty()) {
        backStack.push(currentLocation); // current goes to back history
    }

    currentLocation = newLocation;

    // when visiting a new location, forward history is cleared
    while (!forwardStack.empty()) {
        forwardStack.pop();
    }

    cout << "You are now at: " << currentLocation << endl;
}

void goBack(stack<string> &backStack, stack<string> &forwardStack, string &currentLocation) {
    if (backStack.empty()) {
        cout << "No previous location to go back to.\n";
        return;
    }

    forwardStack.push(currentLocation);        // current goes to forward stack
    currentLocation = backStack.top();         // move to previous
    backStack.pop();

    cout << "You moved back to: " << currentLocation << endl;
}

void goForward(stack<string> &backStack, stack<string> &forwardStack, string &currentLocation) {
    if (forwardStack.empty()) {
        cout << "No forward location available.\n";
        return;
    }

    backStack.push(currentLocation);          // current goes to back stack
    currentLocation = forwardStack.top();     // move to next
    forwardStack.pop();

    cout << "You moved forward to: " << currentLocation << endl;
}

void showCurrentLocation(const string &currentLocation) {
    if (currentLocation.empty()) {
        cout << "You are not at any location yet.\n";
    } else {
        cout << "Current location: " << currentLocation << endl;
    }
}

void showHistory(stack<string> backStack, stack<string> forwardStack, const string &currentLocation) {
    cout << "\n--- Navigation History ---\n";

    cout << "Back stack (from oldest to newest): ";
    // To print from bottom to top, we reverse by using a temporary stack
    stack<string> temp;
    while (!backStack.empty()) {
        temp.push(backStack.top());
        backStack.pop();
    }
    if (temp.empty()) {
        cout << "(empty)";
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
        if (!temp.empty()) cout << " -> ";
    }
    cout << endl;

    cout << "Current location: ";
    if (currentLocation.empty()) cout << "(none)";
    else cout << currentLocation;
    cout << endl;

    cout << "Forward stack (from newest to oldest): ";
    if (forwardStack.empty()) {
        cout << "(empty)";
    } else {
        while (!forwardStack.empty()) {
            cout << forwardStack.top();
            forwardStack.pop();
            if (!forwardStack.empty()) cout << " -> ";
        }
    }
    cout << "\n--------------------------\n";
}

int main() {
    stack<string> backStack;
    stack<string> forwardStack;
    string currentLocation = "";

    int choice;

    do {
        cout << "\n===== NAVIGATION APP USING STACKS =====\n";
        cout << "1. Visit new location\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Show current location\n";
        cout << "5. Show history\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                visitNewLocation(backStack, forwardStack, currentLocation);
                break;
            case 2:
                goBack(backStack, forwardStack, currentLocation);
                break;
            case 3:
                goForward(backStack, forwardStack, currentLocation);
                break;
            case 4:
                showCurrentLocation(currentLocation);
                break;
            case 5:
                showHistory(backStack, forwardStack, currentLocation);
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
