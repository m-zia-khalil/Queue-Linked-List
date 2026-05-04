#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Queue {
private:
    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() {
        frontPtr = NULL;
        rearPtr = NULL;
    };

    // Check if queue is empty 
    int isEmpty() {
        if (frontPtr == NULL)
            return 1;
        else
            return 0;
    }

    // instert at rear
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty() == 1) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        cout << val << " enqueued.\n";
    }

    // remove from front
    void dequeue() {
        if (isEmpty() == 1) {
            cout << "Queue Underflow! Cannot dequeue from empty queue.\n";
            return;
        }
        Node* temp = frontPtr;
        cout << temp->data << " dequeued.\n";
        frontPtr = frontPtr->next;
        if (frontPtr == NULL)
            rearPtr = NULL;
        delete temp;
    }

    // View front element
    void front() {
        if (isEmpty() == 1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element: " << frontPtr->data << "\n";
    }

    // Display queue contents
    void display() {
        if (isEmpty() == 1) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        Node* temp = frontPtr;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~Queue() {
        while (isEmpty() == 0) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    int choice, val;

    choice = -1;
    while (choice != 0) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Front\n";
        cout << "4. Is Empty?\n";
        cout << "5. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            q.display();
        }
        else if (choice == 2) {
            q.dequeue();
            q.display();
        }
        else if (choice == 3) {
            q.front();
        }
        else if (choice == 4) {
            if (q.isEmpty() == 1) {
                cout << "Queue is empty.\n";
            }
            else {
                cout << "Queue is not empty.\n";
            }
        }
        else if (choice == 5) {
            q.display();
        }
        else if (choice == 0) {
            cout << "Exiting.\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}