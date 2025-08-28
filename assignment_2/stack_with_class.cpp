#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

class Stack {
private:
    int *stack;
    int top;
    int size;

public:
    Stack(int stackSize) : size(stackSize), top(-1) {
        stack = new int[size];
        if (stack == NULL) {
            cout << "Memory allocation failed." << endl;
            exit(1);
        }
    }

    ~Stack() {
        delete[] stack;
    }

    int isEmpty() {
        return top == -1;
    }

    int isFull() {
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
};

int main() {
    int stackSize, choice;
    cout << "Enter stack size(n): ";
    cin >> stackSize;
    if (stackSize <= 0) {
        cout << "Invalid stack size. Must be positive." << endl;
        return 1;
    }

    Stack stack(stackSize);

    while (1) {
        cout << endl << "Select operation to perform:" << endl;
        cout << "1. View stack" << endl << "2. Push" << endl << "3. Pop" << endl << "4. Peek" << endl << "5. Exit" << endl << "Selection: ";
        cin >> choice;
        while (choice <= 0 || choice >= 6) {
            cout << "Invalid selection" << endl << "Selection: ";
            cin >> choice;
        }
        switch (choice) {
            case 1: stack.viewStack(); break;
            case 2: {
                int data;
                cout << "Enter element to push: ";
                cin >> data;
                stack.push(data);
                break;
            }
            case 3: stack.pop(); break;
            case 4: stack.peek(); break;
            case 5: 
                return 0;
        }
    }
}
