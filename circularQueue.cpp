#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int size;
    int* queue;

public:
    // Constructor to initialize queue
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full!" << endl;
            return;
        } 
        else if (front == -1) {  // First element insertion
            front = rear = 0;
        } 
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        } 
        else {
            rear++;
        }
        queue[rear] = value;
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << queue[front] << " dequeued from the queue." << endl;

        if (front == rear) {  // Single element case
            front = rear = -1;
        } 
        else if (front == size - 1) {
            front = 0;  // Wrap-around
        } 
        else {
            front++;
        }
    }

    // Display the queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue Elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } 
        else {
            for (int i = front; i < size; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    int size, choice, value;

    cout << "Enter the size of the queue: ";
    cin >> size;

    CircularQueue q(size);

    while (true) {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Enqueue (Insert)" << endl;
        cout << "2. Dequeue (Delete)" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
