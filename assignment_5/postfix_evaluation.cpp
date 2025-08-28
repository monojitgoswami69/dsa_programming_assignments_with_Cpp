#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int *stack;
int top = -1;
int maxSize;

int pop() {
    if (top == -1) {
        cout << "Stack Underflow - cannot pop" << endl;
        return 0;
    }
    return stack[top--];
}

void push(int value) {
    if (top == maxSize - 1) {
        cout << "Stack Overflow - cannot push " << value << endl;
        return;
    }
    stack[++top] = value;
}

void evaluate(const string& postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        if (c >= '0' && c <= '9') {
            push(c - '0'); 
        } else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': 
                    if (b == 0) {
                        cout << "Error: Division by zero" << endl;
                        return;
                    }
                    push(a / b); 
                    break;
                default: 
                    cout << "Invalid operator: " << c << endl;
                    return;
            }
        }
    }
    cout << "Result: " << pop() << endl;
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    cout << "Enter maximum stack size: ";
    cin >> maxSize;
    
    if (maxSize <= 0) {
        cout << "Invalid stack size" << endl;
        return 1;
    }
    
    stack = new int[maxSize];
    evaluate(postfix);
    delete[] stack;
    
    return 0;
}
