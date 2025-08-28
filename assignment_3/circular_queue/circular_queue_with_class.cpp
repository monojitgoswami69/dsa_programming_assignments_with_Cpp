#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class CircularQueue {
private:
    int *queue;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int queueSize) : front(-1), rear(-1), size(queueSize) {
        if (size <= 0) {
            cout << "Invalid queue size. Setting to default size 10." << endl;
            size = 10;
        }
        queue = new int[size];
        if (queue == NULL) {
            cout << "Memory allocation failed." << endl;
            exit(1);
        }
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        if (isEmpty()) return false;
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
};

int main() {
    int queueSize, choice, data;
    cout << "Enter queue size: ";
    cin >> queueSize;

    CircularQueue queue(queueSize);

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
                queue.enqueue(data);
                break;
            }
            case 2: queue.dequeue(); break;
            case 3: queue.display(); break;
            case 4: queue.peek(); break;
            case 5: return 0;
        }
    }
}
