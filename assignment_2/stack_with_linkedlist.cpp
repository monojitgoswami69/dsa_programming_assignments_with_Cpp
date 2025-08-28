#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct stackNode {
    int data;
    struct stackNode *next;
};

typedef struct stackNode* stack;

stack top = NULL;

int isEmpty() {
    return top == NULL;
}

void viewStack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    
    cout << "Stack -" << endl;
    stack current = top;
    int isFirst = 1;
    
    while (current != NULL) {
        if (isFirst) {
            cout << current->data << " <- Top" << endl;
            isFirst = 0;
        } else {
            cout << current->data << endl;
        }
        current = current->next;
    }
    cout << endl;
}

void push(int x) {
    stack newNode = new stackNode;
    if (newNode == NULL) {
        cout << "Stack Overflow" << endl;
        return;
    }
    
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << "Element " << x << " pushed" << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    
    stack temp = top;
    cout << "Popped: " << temp->data << endl;
    top = top->next;
    delete temp;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << top->data << " <- Top" << endl;
}

int main() {
    int choice;
    while (1) {
        cout << endl << "Select operation to perform:" << endl;
        cout << "1. View stack" << endl << "2. Push" << endl << "3. Pop" << endl << "4. Peek" << endl << "5. Exit" << endl << "Selection: ";
        cin >> choice;
        while (choice <= 0 || choice >= 6) {
            cout << "Invalid selection" << endl << "Selection: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: viewStack(); break;
            case 2: {
                int data;
                cout << "Enter element to push: ";
                cin >> data;
                push(data);
                break;
            }
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                while (top != NULL) {
                    stack temp = top;
                    top = top->next;
                    delete temp;
                }
                return 0;
        }
    }
}
