#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int *arr = NULL;
int n = 0;

void reAllocate(int mode){
    if (n + mode <= 0) {
        if (arr != NULL) {
            delete[] arr;
            arr = NULL;
        }
        n = 0;
        return;
    }
    int *temp = new int[n + mode];
    if (temp == NULL) {
        cout << "Memory Allocation failed\n";
        return;
    }
    int copySize = min(n, n + mode);
    for (int i = 0; i < copySize; i++) {
        temp[i] = arr[i];
    }
    
    if (mode > 0) {
        temp[n] = 0;
    }
    
    delete[] arr;
    arr = temp; 
    n += mode;
}

void readArray(int size){
    if (arr != NULL) {
        delete[] arr;
        arr = NULL;
    }
    if (size <= 0) {
        cout << "Invalid array length\n";
        n = 0;
        return;
    }
    arr = new int[size];
    if (arr == NULL){
        cout << "Memory Allocation failed\n";
        n = 0;
        return;
    }
    n = size;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Array read successfully.\n";
}

void displayArray(){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Please read array first.\n";
        return;
    }
    cout << "Current array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void insertElement(int element, int position){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Please read array first.\n";
        return;
    }
    if (!(position > 0 && position <= n + 1)){
        cout << "Invalid position\n";
        return;
    }
    reAllocate(1);
    if (arr == NULL) return; 
    for (int i = n - 1; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = element;
    cout << "Element " << element << " inserted at position " << position << " successfully.\n";
}

void deleteElement(int element){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == element){
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            reAllocate(-1);
            cout << "Element " << element << " deleted successfully.\n";
            return;
        }
    }
    cout << "Element not found\n";
}

void deleteElementIndex(int position){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }
    if (!(position <= n && position >= 1)){
        cout << "Position out of bounds\n";
        return;
    }
    int deletedElement = arr[position - 1];
    for (int j = position - 1; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }
    reAllocate(-1);
    cout << "Element " << deletedElement << " at position " << position << " deleted successfully.\n";
}

void searchElement(int element){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Please read array first.\n";
        return;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == element){
            cout << "Element found at position: " << (i + 1) << "\n";
            return;
        }
    }
    cout << "Element not found\n";
}

void sortArray(){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Please read array first.\n";
        return;
    }
    int swapped;
    for (int i = 0; i < n-1; i++){
        swapped = 0; 
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (!swapped) {
            break;
        }
    }
    cout << "Array sorted successfully\n";
}

void binarySearchElement(int element){
    if (arr == NULL || n == 0){
        cout << "Array is empty. Please read array first.\n";
        return;
    }
    sortArray();
    cout << "Array sorted for binary search: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == element){
            cout << "Element found at position: " << (mid + 1) << " (in sorted array)\n";
            return;
        }
        if (arr[mid] < element){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Element not found\n";
}

int main(){
    int choice;
    while (1){
        cout << "\nEnter operation to perform-\n";
        cout << "1. Read Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert element\n";
        cout << "4. Delete element\n";
        cout << "5. Delete element from position\n";
        cout << "6. Search element (Linear Search)\n";
        cout << "7. Sort Array\n";
        cout << "8. Search element (Binary Search)\n";
        cout << "9. quit\n";
        cout << "Selection: ";
        cin >> choice;
        
        if (choice == 9) {
            if (arr != NULL) {
                delete[] arr;
            }
            return 0;
        }
        if (!(choice > 0 && choice <= 9)){
            cout << "Invalid input\n";
            continue; 
        }
        
        switch(choice){
            case 1: {
                int size;
                cout << "Enter array length: ";
                cin >> size;
                readArray(size);
                break;
            }
            case 2: 
                displayArray(); 
                break;
            case 3: {
                int element, position;
                cout << "Enter element and position to insert: ";
                cin >> element >> position;
                insertElement(element, position);
                break;
            }
            case 4: {
                int element;
                cout << "Enter element to remove: ";
                cin >> element;
                deleteElement(element);
                break;
            }
            case 5: {
                int position;
                cout << "Enter the position of the element to delete: ";
                cin >> position;
                deleteElementIndex(position);
                break;
            }
            case 6: {
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                searchElement(element);
                break;
            }
            case 7: {
                sortArray();
                break;
            }
            case 8: {
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                binarySearchElement(element);
                break;
            }
        }
    }
}   