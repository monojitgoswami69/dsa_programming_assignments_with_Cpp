#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct NodeStruct {
    int data;
    struct NodeStruct *next;
};

struct QueueStruct {
    struct NodeStruct *rear;
    int size;
    int capacity;
};

typedef struct NodeStruct Node;
typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.rear == NULL;
}

int isFull() {
    return queue.size == queue.capacity;
}

void enqueue(int data) {
    if (isFull()) {
        cout << "Queue Overflow - cannot enqueue " << data << endl;
        return;
    }
    
    Node *newNode = new Node;
    if (newNode == NULL) {
        cout << "Memory allocation failed - cannot enqueue " << data << endl;
        return;
    }
    
    newNode->data = data;
    
    if (isEmpty()) {
        newNode->next = newNode;
        queue.rear = newNode;
    } else {
        newNode->next = queue.rear->next;
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
    
    queue.size++;
    cout << "Enqueued: " << data << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow - cannot dequeue" << endl;
        return;
    }
    
    Node *front = queue.rear->next;
    cout << "Dequeued: " << front->data << endl;
    
    if (queue.size == 1) {
        delete front;
        queue.rear = NULL;
    } else {
        queue.rear->next = front->next;
        delete front;
    }
    
    queue.size--;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    cout << "Queue contents: Front -> ";
    Node *current = queue.rear->next;
    
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != queue.rear->next);
    
    cout << "<- Rear" << endl;
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty - cannot peek" << endl;
        return;
    }
    cout << "Front: " << queue.rear->next->data << endl;
    cout << "Rear: " << queue.rear->data << endl;
}

void freeQueue() {
    if (isEmpty()) return;
    
    Node *current = queue.rear->next;
    Node *temp;
    
    do {
        temp = current;
        current = current->next;
        delete temp;
    } while (current != queue.rear->next);
    
    queue.rear = NULL;
    queue.size = 0;
}

int main() {
    int capacity, choice, data;
    
    cout << "Enter queue capacity: ";
    cin >> capacity;
    
    if (capacity <= 0) {
        cout << "Invalid queue capacity" << endl;
        return 1;
    }
    
    queue.rear = NULL;
    queue.size = 0;
    queue.capacity = capacity;
    
    cout << "Circular Queue with Linked List (capacity " << capacity << ") created successfully!" << endl;
    
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
                freeQueue();
                cout << "Queue freed successfully!" << endl;
                return 0;
        }
    }
    
    return 0;
}
