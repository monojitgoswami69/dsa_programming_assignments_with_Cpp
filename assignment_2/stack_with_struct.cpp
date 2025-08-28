#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct StackStruct {
    int *arr;
    int top;
    int size;
};

typedef struct StackStruct Stack;

Stack stack;

int isEmpty() {
    return stack.top == -1;
}

int isFull() {
    return stack.top == stack.size - 1;
}

void viewStack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack -" << endl << stack.arr[stack.top] << " <- Top" << endl;
    for (int i = stack.top - 1; i >= 0; i--)
        cout << stack.arr[i] << endl;
    cout << endl;
}

void push(int x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack.top++;
    stack.arr[stack.top] = x;
    cout << "Element " << x << " pushed" << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Popped: " << stack.arr[stack.top] << endl;
    stack.top--;
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << stack.arr[stack.top] << " <- Top" << endl;
}

int main() {
    int choice;
    cout << "Enter stack size(n): ";
    cin >> stack.size;
    if (stack.size <= 0) {
        cout << "Invalid stack size. Must be positive." << endl;
        return 1;
    }
    stack.arr = new int[stack.size];
    if (stack.arr == NULL) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }
    stack.top = -1;
    
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
                delete[] stack.arr;
                return 0;
        }
    }
}
