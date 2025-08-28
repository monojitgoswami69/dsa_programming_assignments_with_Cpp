#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node {
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int value) {
    struct Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    cout << "Inserted " << value << " at beginning" << endl;
}

void insertAtEnd(struct Node **head, int value) {
    struct Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at end" << endl;
}

void insertAtK(struct Node **head, int value, int k) {
    if (k <= 0) {
        cout << "Invalid position! Position should be >= 1" << endl;
        return;
    }

    if (k == 1) {
        insertAtBeginning(head, value);
        return;
    }
    
    struct Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return;
    }
    newNode->data = value;
    
    struct Node *temp = *head;
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

void deleteFromBeginning(struct Node **head) {
    if (*head == nullptr) {
        cout << "List is empty! Nothing to delete" << endl;
        return;
    }
    
    struct Node *temp = *head;
    *head = (*head)->next;
    cout << "Deleted " << temp->data << " from beginning" << endl;
    delete temp;
}

void deleteFromEnd(struct Node **head) {
    if (*head == nullptr) {
        cout << "List is empty! Nothing to delete" << endl;
        return;
    }
    
    if ((*head)->next == nullptr) {
        cout << "Deleted " << (*head)->data << " from end" << endl;
        delete *head;
        *head = nullptr;
        return;
    }
    
    struct Node *temp = *head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    
    cout << "Deleted " << temp->next->data << " from end" << endl;
    delete temp->next;
    temp->next = nullptr;
}

void deleteFromK(struct Node **head, int k) {
    if (*head == nullptr) {
        cout << "List is empty! Nothing to delete" << endl;
        return;
    }
    
    if (k <= 0) {
        cout << "Invalid position! Position should be >= 1" << endl;
        return;
    }
    
    if (k == 1) {
        deleteFromBeginning(head);
        return;
    }
    
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position " << k << " is out of bounds" << endl;
        return;
    }
    
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    cout << "Deleted " << nodeToDelete->data << " from position " << k << endl;
    delete nodeToDelete;
}

void display(struct Node *head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    
    cout << "List: ";
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

void search(struct Node *head, int value) {
    int position = 1;
    while (head != nullptr) {
        if (head->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        head = head->next;
        position++;
    }
    cout << "Value " << value << " not found in the list" << endl;
}

void reverse(struct Node **head) {
    if (*head == nullptr) {
        cout << "List is empty! Nothing to reverse" << endl;
        return;
    }
    
    struct Node *prev = nullptr;
    struct Node *current = *head;
    struct Node *next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
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

int main() {
    struct Node *head = nullptr;
    int choice, value, position;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(&head, value);
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(&head, value);
                break;
                
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position (1-indexed): ";
                cin >> position;
                insertAtK(&head, value, position);
                break;
                
            case 4:
                deleteFromBeginning(&head);
                break;
                
            case 5:
                deleteFromEnd(&head);
                break;
                
            case 6:
                cout << "Enter position to delete (1-indexed): ";
                cin >> position;
                deleteFromK(&head, position);
                break;
                
            case 7:
                display(head);
                break;
                
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;
                
            case 9:
                reverse(&head);
                break;
                
            case 0:               
                while (head != nullptr) {
                    struct Node *temp = head;
                    head = head->next;
                    delete temp;
                }
                return 0;
                
            default:
                cout << "Invalid choice! Please enter a number between 0-9" << endl;
                break;
        }
    }
    
    return 0;
}
