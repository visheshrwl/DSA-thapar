#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Function prototypes
int createArray(int arr[]);
void displayArray(int arr[], int size);
void insertElement(int arr[], int& size);
void deleteElement(int arr[], int& size);
void linearSearch(int arr[], int size, int element);

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        // Display menu
        cout << "\n-------- MENU --------" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                size = createArray(array);
                break;
            case 2:
                displayArray(array, size);
                break;
            case 3:
                insertElement(array, size);
                break;
            case 4:
                deleteElement(array, size);
                break;
            case 5: {
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                linearSearch(array, size, element);
                break;
            }
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}

int createArray(int arr[]) {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Array created successfully!" << endl;
    return size;
}

void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size) {
    int element, index;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the index at which to insert the element: ";
    cin >> index;

    if (index >= 0 && index <= size) {
        for (int i = size; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        ++size;
        cout << "Element inserted successfully!" << endl;
    } else {
        cout << "Invalid index. Insertion failed." << endl;
    }
}

void deleteElement(int arr[], int& size) {
    int element;
    cout << "Enter the element to delete: ";
    cin >> element;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --size;
        cout << "Element deleted successfully!" << endl;
    } else {
        cout << "Element not found in the array. Deletion failed." << endl;
    }
}

void linearSearch(int arr[], int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            cout << "Element found at index " << i << "." << endl;
            return;
        }
    }
    cout << "Element not found in the array." << endl;
}
