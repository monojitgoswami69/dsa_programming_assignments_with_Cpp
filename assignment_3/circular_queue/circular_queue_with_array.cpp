#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int *queue;
int front = -1;
int rear = -1;
int size = 0;

int isEmpty() {
    return front == -1;
}

int isFull() {
    if (isEmpty()) return 0;
    return (rear + 1) % size == front % size;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue Overflow - cannot enqueue " << data << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }
    rear++;
    queue[rear % size] = data;
    cout << "Enqueued: " << data << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow - cannot dequeue" << endl;
        return;
    }
    cout << "Dequeued: " << queue[front % size] << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue contents: Front -> ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i % size] << " ";
    }
    cout << "<- Rear" << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty - cannot peek" << endl;
        return;
    }
    cout << "Front: " << queue[front % size] << endl;
    cout << "Rear: " << queue[rear % size] << endl;
}

int main() {
    int choice, data;
    cout << "Enter queue size: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid queue size. Must be positive." << endl;
        return 1;
    }
    
    queue = new int[size];
    if (queue == NULL) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }
    while (1) {
        cout << endl << "=== Circular Queue Operations ===" << endl;
        cout << "1. Enqueue(Insert)" << endl;
        cout << "2. Dequeue(Remove)" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Exit" << endl;
        cout << "Selection: ";
        cin >> choice;
        cout << endl;
        while (choice < 1 || choice > 5) {
            cout << "Invalid selection" << endl;
            cout << "Selection: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: {
                cout << "Enter element to enqueue: ";
                cin >> data;
                enqueue(data);
                break;
            }
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: 
                delete[] queue;
                return 0;
        }
    }
}
