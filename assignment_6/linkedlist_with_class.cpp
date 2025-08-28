#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int data;
    Node *next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (newNode == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (newNode == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at end" << endl;
    }

    void insertAtK(int value, int k) {
        if (k <= 0) {
            cout << "Invalid position! Position should be >= 1" << endl;
            return;
        }

        if (k == 1) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        if (newNode == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return;
        }
        
        Node *temp = head;
        for (int i = 1; i < k - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position " << k << " is out of bounds" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << k << endl;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete" << endl;
            return;
        }
        
        Node *temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning" << endl;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Deleted " << temp->next->data << " from end" << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFromK(int k) {
        if (head == nullptr) {
            cout << "List is empty! Nothing to delete" << endl;
            return;
        }
        
        if (k <= 0) {
            cout << "Invalid position! Position should be >= 1" << endl;
            return;
        }
        
        if (k == 1) {
            deleteFromBeginning();
            return;
        }
        
        Node *temp = head;
        for (int i = 1; i < k - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position " << k << " is out of bounds" << endl;
            return;
        }
        
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted " << nodeToDelete->data << " from position " << k << endl;
        delete nodeToDelete;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "List: ";
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int value) {
        int position = 1;
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Value " << value << " not found in the list" << endl;
    }

    void reverse() {
        if (head == nullptr) {
            cout << "List is empty! Nothing to reverse" << endl;
            return;
        }
        
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        cout << "List reversed successfully" << endl;
    }

    void displayMenu() {
        cout << endl << "===== LINKED LIST MENU =====" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position k" << endl;
        cout << "4. Delete from beginning" << endl;
        cout << "5. Delete from end" << endl;
        cout << "6. Delete from position k" << endl;
        cout << "7. Display list" << endl;
        cout << "8. Search for value" << endl;
        cout << "9. Reverse list" << endl;
        cout << "0. Quit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
    }
};

int main() {
    LinkedList list;
    int choice, value, position;
    
    while (true) {
        list.displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (1-indexed): ";
                cin >> position;
                list.insertAtK(value, position);
                break;
                
            case 4:
                list.deleteFromBeginning();
                break;
                
            case 5:
                list.deleteFromEnd();
                break;
                
            case 6:
                cout << "Enter position to delete (1-indexed): ";
                cin >> position;
                list.deleteFromK(position);
                break;
                
            case 7:
                list.display();
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
                
            case 9:
                list.reverse();
                break;
                
            case 0:               
                return 0;
                
            default:
                cout << "Invalid choice! Please enter a number between 0-9" << endl;
                break;
        }
    }
    
    return 0;
}
