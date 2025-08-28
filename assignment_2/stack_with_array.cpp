#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int *stack;
int top = -1;
int size;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == size - 1;
}

void viewStack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack -" << endl << *(stack + top) << " <- Top" << endl;
    for (int i = top - 1; i >= 0; i--)
        cout << *(stack + i) << endl;
    cout << endl;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    top++;
    *(stack + top) = x;
    cout << "Element " << x << " pushed" << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Popped: " << *(stack + top) << endl;
    top--;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << *(stack + top) << " <- Top" << endl;
}

int main() {
    int choice;
    cout << "Enter stack size(n): ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid stack size. Must be positive." << endl;
        return 1;
    }
    stack = new int[size];
    if (stack == NULL) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }
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
                delete[] stack;
                return 0;
        }
    }
}
