#include <iostream>
#include <climits>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Class for Singly Linked List
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node
    void insert(int value, int pos) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // Case 1: Insert at the beginning
        if (pos == 0 || head == nullptr) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at the beginning." << endl;
            return;
        }

        // Case 2 & 3: Insert at specific position or end
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp->next == nullptr) {
                cout << "Position out of range! Inserting at the end." << endl;
                break;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << "." << endl;
    }

    // Display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main Function
int main() {
    SinglyLinkedList list;
    int choice, value, pos;

    while (true) {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert at Specific Position";
        cout << "\n4. Display List";
        cout << "\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:  // Insert at beginning
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value, 0);
                break;

            case 2:  // Insert at end
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value, INT_MAX);  // Large value for end insertion
                break;

            case 3:  // Insert at specific position
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert: ";
                cin >> pos;
                list.insert(value, pos);
                break;

            case 4:  // Display the list
                cout << "\nLinked List: ";
                list.display();
                break;

            case 5:  // Exit
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
