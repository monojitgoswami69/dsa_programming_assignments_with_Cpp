#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

char *stack;
int top = -1;
int maxSize;

int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0; 
}

void push(char c) {
    if (top == maxSize - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return '\0';
    }
    return stack[top--];
}

void convert(const string& infix){
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char key = infix[i];
        
        if ((key >= '0' && key <= '9') || (key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z')) {
            postfix += key;
        } 
        else if (key == '*' || key == '/' || key == '+' || key == '-' || key == '^') {
            if (key == '^') {
                while (top != -1 && priority(stack[top]) > priority(key)) {
                    postfix += pop();
                }
            } else {
                while (top != -1 && priority(stack[top]) >= priority(key)) {
                    postfix += pop();
                }
            }
            push(key);
        }
        else if (key == '(') {
            push(key);
        } 
        else if (key == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix += pop();
            }
            if (top != -1) {
                pop(); 
            }
        }
        else {
            cout << "Invalid character: " << key << endl;
            return;
        }
    }
    
    while (top != -1) {
        postfix += pop();
    }
    
    cout << "Postfix: " << postfix << endl;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    cout << "Enter maximum stack size: ";
    cin >> maxSize;
    
    if (maxSize <= 0) {
        cout << "Invalid stack size" << endl;
        return 1;
    }
    
    stack = new char[maxSize];
    convert(infix);
    delete[] stack;
    
    return 0;
}
