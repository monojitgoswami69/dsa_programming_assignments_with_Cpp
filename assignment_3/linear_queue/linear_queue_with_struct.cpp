#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct QueueStruct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
};

typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.size == 0;
}

int isFull() {
    return queue.size == queue.capacity;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue Overflow - cannot enqueue " << data << endl;
        return;
    }
    if (isEmpty()) {
        queue.front = 0;
        queue.rear = -1;
    }
    queue.rear++;
    queue.data[queue.rear] = data;
    queue.size++;
    cout << "Enqueued: " << data << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow - cannot dequeue" << endl;
        return;
    }
    cout << "Dequeued: " << queue.data[queue.front] << endl;
    queue.front++;
    queue.size--;
    
    if (queue.size == 0) {
        queue.front = -1;
        queue.rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue contents: Front -> ";
    for (int i = queue.front; i <= queue.rear; i++) {
        cout << queue.data[i] << " ";
    }
    cout << "<- Rear" << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty - cannot peek" << endl;
        return;
    }
    cout << "Front: " << queue.data[queue.front] << endl;
    cout << "Rear: " << queue.data[queue.rear] << endl;
}

int main() {
    int capacity, choice, data;
    
    cout << "Enter queue capacity: ";
    cin >> capacity;
    
    if (capacity <= 0) {
        cout << "Invalid queue capacity" << endl;
        return 1;
    }
    
    queue.data = new int[capacity];
    if (queue.data == NULL) {
        cout << "Memory allocation failed for queue data" << endl;
        return 1;
    }
    
    queue.front = -1;
    queue.rear = -1;
    queue.size = 0;
    queue.capacity = capacity;
    
    cout << "Queue with capacity " << capacity << " created successfully!" << endl;
    
    while (1) {
        cout << endl << "=== Queue Operations ===" << endl;
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
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                delete[] queue.data;
                return 0;
        }
    }
    
    return 0;
}
